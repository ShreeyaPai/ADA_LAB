#include<stdio.h>
#include<stdlib.h>
int count;
void swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int bubblesort(int a[],int n)
{
	count=0;
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				flag=1;
				swap(&a[j],&a[j+1]);
			}
		}
		if(flag==0) return count;
	}
	return count;
}

void main()
{
	FILE *b,*w;
	b=fopen("bubblebest.txt","w");
	w=fopen("bubbleworst.txt","w");
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
		count=bubblesort(a,n);
		/*for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");*/
		printf("%d\n",count);
		fprintf(w,"%d\t%d\n",n,count);
		
		//best case
		count=0;
		/*for(int i=0;i<n;i++)
		{
			a[i]=i;
		}*/
		count=bubblesort(a,n);
		/*for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}*/
		//printf("\n");
		printf("%d\n",count);
		fprintf(b,"%d\t%d\n",n,count);
		free(a);
	}
	//fclose(b);
	//fclose(w);
}
