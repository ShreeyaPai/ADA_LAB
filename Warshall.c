#include<stdio.h>
#include<stdlib.h>

int graph[25][25],n;
//Commented part is for analysis
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
			else graph[i][j]=1;
		}
	}
}

void Transitive()
{
	printf("Transitive Closure Mtarix is:\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	createGraph(); //Use this for correctness
	//FILE *w=fopen("Warshall.txt","w");
	//for(int n=2;n<=11;n++)
	//{
		//generateGraph(n);
		int count=0;
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				if(graph[i][k])
				{
					for(int j=0;j<n;j++)
					{
						count++;
						if(graph[k][j])
							graph[i][j]=1;
					}
				}
			}
		}
		printf("%d\n",count);
		//fprintf(w,"%d\t%d\n",n,count);
	//}
	Transitive(); //Use this for correctness
}













