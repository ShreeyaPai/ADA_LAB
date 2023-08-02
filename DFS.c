#include<stdio.h>
#include<stdlib.h>

int graph[25][25],visited[25],count,cnt=0,stack[25],path[25],fin,isCyclic=0,n,D;

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

void dfs(int n,int parent,int start)
{
	visited[start]=1;
	count++;
	path[start]=1;
	//printf("-->%c",start+65);
	for(int i=0;i<n;i++)
	{
		fin++; //final count for analysis
		if(D && i!=parent && graph[start][i] && visited[i] && path[i]) //path is for directed
		{
			isCyclic=1;
		}
		if(!D && i!=parent && graph[start][i] && visited[i]) //path is for directed
		{
			isCyclic=1;
		}
		if(graph[start][i] && !visited[i])
		{
			dfs(n,start,i);
		}
	}
	path[start]=0;
}

void main()
{
		/*createGraph();
  		printf("Enter 1 for directed and 0 for undirected\n");
    		scanf("%d",&D);
		dfs(n,-1,0);
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
				dfs(n,-1,i);
				printf("\n");
				}
			}
		}*/
	FILE *b=fopen("dfs.txt","w");
		for(int n=2;n<=15;n++)
		{
			isCyclic=0;
			cnt=0;
			fin=0;
			count=0;
			createGraph(n);
			dfs(n,-1,0);
			for(int i=0;i<n;i++)
				{
					if(!visited[i]) 
					{
					dfs(n,-1,i);
					}
				}
			printf("%d\n",fin);
			fprintf(b,"%d\t%d\n",n,fin);
		}
}
	
	
	
	
	
	
	
	
	
	
	
