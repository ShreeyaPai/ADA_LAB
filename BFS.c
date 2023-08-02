#include<stdio.h>
#include<stdlib.h>

int graph[25][25],visited[25],count,isCyclic,fin,n,count,path[25],D;

/*void createGraph(){  //to get input from user and store it in graph matrix
	int i,j;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
		visited[i]=0;
	}
}*/

void createGraph(int n){  
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=0;
		}
		visited[i]=0;
	}
}

void bfs(int n,int start)
{
	int q[25],parent[25],parentNode,r=-1,f=-1;
	q[++r]=start;
	parent[r]=-1;
	visited[start]=1;
	count++;
	while(f!=r)
	{
	path[start]=1;
	parentNode=parent[++f];
	start=q[f];
	//printf("--> %c",start+65);
	for(int i=0;i<n;i++)
	{
		fin++;
		if(D && i!=parentNode && graph[start][i] && visited[i] && path[i]) //path is for directed
		{
			isCyclic=1;
		}
		if(!D && i!=parentNode && graph[start][i] && visited[i]) //path is for directed
		{
			isCyclic=1;
		}
		if(graph[start][i] && !visited[i])
		{
			parent[++r]=start;
			q[r]=i;
			visited[i]=1;
			count++;
		}
	}
	path[start]=0;
	}
	
}

void main()
{
		/*createGraph();
  	printf("Enter 1 for directed and 0 for undirected\n");
    scanf("%d",&D);
		bfs(n,0);
		printf("\n");
		(isCyclic==1)?printf("It is Cyclic\n"):printf("Not cyclic\n");
		if(count==n)
		{
			printf("It is connected\n");
		}
		else
		{
			printf("It is not connected\n");
			for(int i=0;i<n;i++)
			{
				if(!visited[i]) 
				{
				bfs(n,i);
				printf("\n");
				}
			}
		}
		printf("%d\n",fin);*/
		
		FILE *b=fopen("bfs.txt","w");
		for(int n=2;n<=15;n++)
		{
			isCyclic=0;
			fin=0;
			count=0;
			createGraph(n);
			bfs(n,0);
			for(int i=0;i<n;i++)
				{
					if(!visited[i]) 
					{
					bfs(n,i);
					}
				}
			printf("%d\n",fin);
			fprintf(b,"%d\t%d\n",n,fin);
		}
}
