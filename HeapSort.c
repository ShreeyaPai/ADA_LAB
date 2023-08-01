#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count;

void swap(int* x,int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int a[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n)
	{
		count++;
		if(a[left]>a[largest])
		{
			largest=left;
		}
	}
	if(right<n)
	{
		count++;
		if(a[right]>a[largest])
		{
			largest=right;
		}
	}
	if(largest!=i)
	{
		swap(&a[largest],&a[i]);
		heapify(a,n,largest);
	}
}

void heapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(&a[i],&a[0]);
		heapify(a,i,0);
	}
}

void main()
{
	/*int a[]={3,1,2,4,6,5,7};
	int n=7;
	heapsort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}*/
	FILE *b,*w;
	b=fopen("heapbest.txt","w");
	w=fopen("heapworst.txt","w");
	for(int n=3;n<=1024;n=2*n+1)
	{
	int* a=(int*)malloc(sizeof(int)*n);
	
	//worst case
	count=0;
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	heapsort(a,n);
	fprintf(w,"%d\t%d\n",n,count);
	
	//best case
	count=0;
	for(int i=0;i<n;i++)
	{
		a[i]=n-i;
	}
	heapsort(a,n);
	fprintf(b,"%d\t%d\n",n,count);
	}
	fclose(w);
	fclose(b);
}














