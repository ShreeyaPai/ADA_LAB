#include<stdio.h>
#include<stdlib.h>

int count=0;

int insertionsort(int a[],int n)
{
	count=0;
	int val,j;
	for(int i=0;i<n;i++)
	{
		val=a[i];
		j=i-1;
		while(j>=0 && count++ && val<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
	}
	return count;
}

void main()
{
	FILE *b,*w;
	b=fopen("inbest.txt","w");
	w=fopen("inworst.txt","w");
	int count=0;
	for(int n=100;n<=30000;n=(n<10000)?n*10:n+10000)
	{
		int* a=(int*)malloc(sizeof(int)*n);
		//worst case
		count=0;
		for(int i=0;i<n;i++)
		{
			a[i]=n-i;
		}
		count=insertionsort(a,n);
		fprintf(w,"%d\t%d\n",n,count);
		
		//best case
		count=0;
		count=insertionsort(a,n);
		//printf("%d\n",count);
		fprintf(b,"%d\t%d\n",n,count);
		free(a);
	}
	fclose(b);
	fclose(w);
}
