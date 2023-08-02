#include<stdio.h>
#include<stdlib.h>

int count;

void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


int selectionsort(int a[],int n)
{
	count=0;
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			count++;
			if(a[j]<a[min]) min=j;
		}
		swap(&a[i],&a[min]);
	}
	return count;
}

void main()
{
	FILE *b;
	b=fopen("sel.txt","w");
	count=0;
	for(int n=100;n<=1000;n=n+100)
	{
		int* a=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
		{
			a[i]=n-i;
		}
		count=selectionsort(a,n);
		fprintf(b,"%d\t%d\n",n,count);
		printf("%d\n",count);
		free(a);
	}
	fclose(b);
}
