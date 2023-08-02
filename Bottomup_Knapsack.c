#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

void main()
{
	int n,w[100],m,v[100],a[100][100];
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
			else if(j<w[i])
			{
				a[i][j]=a[i-1][j];
			}
			else
			{
				a[i][j]=max(a[i-1][j],v[i]+a[i-1][j-w[i]]);
			}
		}
	}
	printf("Max value: %d\n",a[n][m]);
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
