#include<stdio.h>
#include<stdlib.h>

int graph[25][25],n;

void createGraph(){  //to get input from user and store it in graph matrix
	int i,j;
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix: \n");
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void generateGraph(int n){  
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;j++){
			if(i==j) graph[i][j]=0;
			else graph[i][j]=rand()%10;
		}
	}
}

void ShortestPath()
{
	printf("Shortest Path Mtarix is:\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int temp;
	//createGraph(); //Use this for correctness
	FILE *w=fopen("Floyd.txt","w");
	for(int n=2;n<=11;n++)
	{
		generateGraph(n);
		int count=0;
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				temp=graph[i][k];
				{
					for(int j=0;j<n;j++)
					{
						if(temp<graph[i][j])
						{
							count++;
							if(temp+graph[k][j]<graph[i][j])
							graph[i][j]=temp+graph[k][j];
						}
					}
				}
			}
		}
		printf("%d\n",count);
		fprintf(w,"%d\t%d\n",n,count);
	}
	//ShortestPath(); //Use this for correctness
}













