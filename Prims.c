#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cost[25][25],n,removed[25],visited[25],heapsize,count,heapcount,graphcount;

typedef struct EDGE
{
	int u,dist,v;
}edge;

edge heap[25],VT[25];

void swap(edge*a,edge*b)
{
	edge temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(edge a[],int n,int i)
{
	heapcount++;
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left].dist<a[largest].dist)
	{
		largest=left;
	}
	if(right<n && a[right].dist<a[largest].dist)
	{
		largest=right;
	}
	if(largest!=i)
	{
		swap(&a[largest],&a[i]);
		heapify(a,n,largest);
	}
}

void heapsort(edge a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
}

edge deletefromheap(edge heap[])
{
	edge min=heap[0];
	heap[0]=heap[heapsize-1];
	heapsize-=1;
	return min;
}

void createGraph()
{
	printf("Enter the  number of vertices: ");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0) cost[i][j]=INT_MAX;
		}
		//visited[i]=0;
		//removed[i]=0;
	}
}

void prim()
{

	heap[heapsize].v=-1;
	heap[heapsize].dist=0;
	heap[heapsize].u=0;
	heapsize++;
	visited[0]=1;

	while(count!=n)
	{
		edge min=deletefromheap(heap);
		VT[count].v=min.v;
		VT[count].dist=min.dist;
		VT[count].u=min.u;
		count++;
		int v=min.u;
		removed[v]=1;
		for(int i=1;i<n;i++)
		{
			if(!visited[i] && cost[v][i]!=INT_MAX && !removed[i])
			{
				heap[heapsize].v=v;
				heap[heapsize].dist=cost[v][i];
				heap[heapsize].u=i;
				heapsize++;
				visited[i]=1;
			}
			if(visited[i] && cost[v][i]!=INT_MAX && !removed[i])
			{
				graphcount++;
				for(int j=0;j<heapsize;j++)
				{
					if(heap[j].u==i && cost[v][i]<heap[j].dist) 
					{
						heap[j].dist=cost[v][i];
						heap[j].v=v;
						break;
					}
				}
			}
		}
		heapsort(heap,heapsize);
	}
}

void main()
{
	createGraph();
	prim();
	int sum=0;
	for(int i=1;i<count;i++)
	{
		printf("%c --> %c = %d \n",VT[i].v+65,VT[i].u+65,VT[i].dist);
		sum+=VT[i].dist;
	}
	printf("Minimum distance is %d\n",sum);
	int fin=(heapcount>graphcount)?heapcount:graphcount;
	printf("%d\n",fin);
}













