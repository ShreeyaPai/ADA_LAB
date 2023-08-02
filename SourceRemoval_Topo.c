#include<stdio.h>
#include<stdlib.h>

int graph[25][25];
int indegree[25],visited[25],source[25],top[25];
int f=0,r=-1,scount=0,fin;

/*void createGraph(){  //to get input from user and store it in graph matrix
	int i,j;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}*/

void generateGraph(int n){  
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			graph[i][j]=0;
		}
	}
}

void computeindegree(int n)
{
	for(int i=0;i<n;i++)
	{
		indegree[i]=0;
		visited[i]=0;
		for(int j=0;j<n;j++)
		{
			if(graph[j][i]) indegree[i]++;
		}
		if(!indegree[i])
		{
			source[++r]=i;
			scount++;
			visited[i]=1;
		}
	}
}

void topo(int n)
{
	int cnt=0;
	while(scount!=0)
	{
		int start=source[f++];
		scount--;
		top[cnt]=start;
		cnt++;
		for(int i=0;i<n;i++)
		{
			fin++;
			if(graph[start][i])
			{
				indegree[i]--;
			}
			if(!visited[i] && !indegree[i])
			{
				source[++r]=i;
				scount++;
				visited[i]=1;
			}
		}
	}
	/*if(cnt!=n)
	{
		printf("Cycles exist\n");
	}
	else
	{
		printf("The topological sorting is:\n");
		for(int i=0;i<n;i++)
		{
			printf("-->%c ",top[i]+65);
		}
	}*/
}

void main()
{
	//createGraph();
	FILE *s=fopen("source.txt","w");
	for(int n=2;n<=15;n++)
	{
	f=0,r=-1;
	fin=0;
	scount=0;
	generateGraph(n);
	computeindegree(n);
	topo(n);
	printf("%d\n",fin);
	fprintf(s,"%d\t%d\n",n,fin);
	}
	fclose(s);
}

