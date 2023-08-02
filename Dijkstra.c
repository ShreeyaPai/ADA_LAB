#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n,src,cost[10][10],d[10]={0},removed[10]={0},count=0,heapsize,heapcount,graphcount;

typedef struct vertex
{
	int id,dist;
}ver;
ver heap[10];

void swap(ver* a,ver*b)
{
	ver temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(ver heap[],int n,int i)
{
	heapcount++;
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && heap[left].dist<heap[i].dist) largest=left;
	if(right<n && heap[right].dist<heap[i].dist) largest=right;
	if(largest!=i) {
	swap(&heap[i],&heap[largest]);
	heapify(heap,n,largest);
	}
}

void heapsort(ver heap[],int heapsize)
{
	for(int i=n/2-1;i<=0;i--)
		heapify(heap,n,i);
}

ver getmin(ver heap[])
{
	ver minvertex=heap[0];
	heap[0]=heap[heapsize-1];
	heapsize-=1;
	heapify(heap,heapsize,0);
	return minvertex;
}

void createGraph()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0) cost[i][j]=INT_MAX;
		}
	}
	
	printf("Enter the source\n");
	scanf("%d",&src);
	for(int i=0;i<n;i++)
	{
		d[i]=INT_MAX;
	}
	d[src]=0;
	
	for(int i=0;i<n;i++)
	{
		heap[i].id=i;
		heap[i].dist=INT_MAX;
	}
	heap[src].dist=0;
	heapsize=n;
	heapsort(heap,heapsize);
}

void dijkstra()
{
	while(count<n)
	{
		ver minvertex=getmin(heap);
		int u=minvertex.id;
		removed[u]=1;
		count++;
		for(int i=0;i<n;i++)
		{
			if(!removed[i] && cost[u][i]!=INT_MAX)
			{
				graphcount++;
				if(cost[u][i] < d[i])
				{
					d[i]=cost[u][i];
					for(int o=0;o<heapsize;o++)
					{
						if(heap[o].id==i) 
						{
							heap[o].dist=d[i];
							break;
						}
					}
					heapsort(heap,heapsize);
				}
			}
		}
	}
}

void main()
{
	createGraph();
	dijkstra();
	sum=0;
	for(int i=0;i<n;i++)
	{
	printf("%d  ",d[i]);
		sum+=d[i];
	}
	printf("%d",sum);
	int fin=(heapcount>graphcount)?heapcount:graphcount;
	printf("%d\n",fin);
}
