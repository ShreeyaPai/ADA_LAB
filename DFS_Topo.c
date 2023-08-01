#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int graph[25][25],visited[25],count,cnt=0,stack[25],path[25],fin;

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

void dfs(int n,int start)
{
	visited[start]=1;
	count++;
	path[start]=1;
	for(int i=0;i<n;i++)
	{
		fin++;
		if(graph[start][i] && visited[i] && path[i])
		{
			printf("Cycles exist!\n");
			exit(0);
		}
		if(graph[start][i] && !visited[i])
		{
			dfs(n,i);
		}
	}
	stack[cnt++]=start;
	path[start]=0;
}

void main()
{
	FILE *b=fopen("dfstop.txt","w");
		for(int n=2;n<=15;n++)
		{
		cnt=0;
		fin=0;
		count=0;
		createGraph(n);
		dfs(n,0);
		for(int i=0;i<n;i++)
		{
			if(!visited[i]) dfs(n,i);
		}
		fprintf(b,"%d\t%d\n",n,fin);
		/*for(int i=n-1;i>=0;i--)
		{
			printf("--> %c",stack[i]+65);
		}*/
		//printf("\n");
	}
	
}










