#include<stdio.h>
#include<stdlib.h>

int n,m,v[100],w[100],a[100][100];

int max(int a,int b)
{
	return (a>b)?a:b;
}

int knap(int i,int j)
{
	if(a[i][j]==-1)
	{
		if(j<w[i]) a[i][j]=knap(i-1,j);
		else a[i][j]=max(knap(i-1,j),v[i]+knap(i-1,j-w[i]));
	}
	return a[i][j];
}

void main()
{
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("\nEnter the capacity: ");
	scanf("%d",&m);
	printf("\nEnter the weight and value of items:\n");
	for(int i=1;i<n+1;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0||j==0)
			{
				a[i][j]=0;
			}
			else
			{
				a[i][j]=-1;			
			}
		}
	}
	printf("Value is %d\n",knap(n,m));
	for(int i=n;i>0;i--)
	{
		if(a[i][m]!=a[i-1][m])
		{
			printf("%d  ",i);
			m-=w[i];
		}
	}
	printf("\n");
}
