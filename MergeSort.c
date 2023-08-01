#include<stdio.h>
#include<stdlib.h>
int count;
void merge(int b[],int c[],int a[],int n)
{
	int n1=n/2,n2=n-n/2;
	int i=0,j=0,k=0;
	while(j<n1 && k<n2)
	{
		count++;
		if(b[j]<=c[k])
		{
			a[i++]=b[j++];
		}
		else
		{
			a[i++]=c[k++];
		}
	}
	while(j<n1)
	{
		a[i++]=b[j++];
	}
	while(k<n2)
	{
		a[i++]=c[k++];
	}
}


void mergesort(int a[],int n)
{
	if(n==1) return;
	int n1=n/2,n2=n-(n/2);
	int b[n1],c[n2];
	for(int i=0;i<n/2;i++)
	{
		b[i]=a[i];
	}
	for(int j=n/2;j<n;j++)
	{
		c[j-n/2]=a[j];
	}
	mergesort(b,n1);
	mergesort(c,n2);
	merge(b,c,a,n);
}

void worst(int a[],int beg,int end)
{
	if(beg<end)
	{
		int mid=(end+beg)/2;
		int n1=(mid-beg)+1;
		int n2=(end-mid);
		int b[n1],c[n2];
		for(int i=0;i<n1;i++)
		{
			b[i]=a[(2*i)];
		}
		for(int i=0;i<n2;i++)
		{
			c[i]=a[(2*i)+1];
		}
		worst(b,beg,mid);
		worst(c,mid+1,end);
		int i;
		for(i=0;i<n1;i++)
		{
		a[i]=b[i];
		}
		for(int j=0;j<n2;j++)
		{
		a[i+j]=c[j];
		}
	}
}




void main()
{
	/*int a[]={1,2,3,4,5,6,7,8};
	int n=8;
	worst(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}*/
	FILE *b,*w;
	b=fopen("mergebest.txt","w");
	w=fopen("mergeworst.txt","w");
	for(int n=2;n<=1024;n=2*n)
	{
	int* a=(int*)malloc(sizeof(int)*n);
	
	//best case
	count=0;
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	mergesort(a,n);
	fprintf(b,"%d\t%d\n",n,count);
	
	//worst case
	count=0;
	worst(a,0,n-1);
	mergesort(a,n);
	fprintf(w,"%d\t%d\n",n,count);
	}
	fclose(w);
	fclose(b);
}










