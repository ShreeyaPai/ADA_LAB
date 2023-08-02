#include<stdio.h>
#include<stdlib.h>

int binary(int a[],int low,int high,int key,int count)
{
	count++;
	int mid=(high+low)/2;
	if(low>high) return count;
	if(a[mid]==key) return count;
	else if(a[mid]>key) return binary(a,low,mid-1,key,count);
	else return binary(a,mid+1,high,key,count);
}

void main()
{
	FILE *b,*w;
	b=fopen("binbest.txt","w");
	w=fopen("binworst.txt","w");
	int bcount=0,wcount=0;
	for(int n=100;n<=30000;n=(n<10000)?n*10:n+10000)
	{
		int* a=(int*)malloc(sizeof(int)*n);
		//worst case
		wcount=0;
		for(int i=0;i<n;i++)
		{
			a[i]=n-i;
		}
		wcount=binary(a,0,n-1,a[n-1],0);
		fprintf(w,"%d\t%d\n",n,wcount);
		
		//best case
		bcount=0;
		bcount=binary(a,0,n-1,a[(n-1)/2],0);
		//printf("%d\n",count);
		fprintf(b,"%d\t%d\n",n,bcount);
		free(a);
	}
	fclose(b);
	fclose(w);
}
