#include<stdio.h>
#include<stdlib.h>

int count;

int linear(int a[],int n,int key)
{
	count=0;
	for(int i=0;i<n;i++)
	{
		count++;
		if(a[i]==key) return count;
	}
	return count;
}

void main()
{
	FILE *b,*w;
	b=fopen("linbest.txt","w");
	w=fopen("linworst.txt","w");
	count=0;
	for(int n=100;n<=30000;n=(n<10000)?n*10:n+10000)
	{
		int* a=(int*)malloc(sizeof(int)*n);
		//worst case
		count=0;
		for(int i=0;i<n;i++)
		{
			a[i]=n-i;
		}
		count=linear(a,n,a[n-1]);
		fprintf(w,"%d\t%d\n",n,count);
		
		//best case
		count=0;
		count=linear(a,n,a[0]);
		//printf("%d\n",count);
		fprintf(b,"%d\t%d\n",n,count);
		free(a);
	}
	fclose(b);
	fclose(w);
}
