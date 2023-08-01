#include<stdio.h>
#include<stdlib.h>

int count=0;

void swap(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int partition(int *a,int beg,int end){
    int i,j,temp;
    i=beg;
    j=end+1;
    int p=a[beg];
    do{
        do{
            i++;
            count++;
        }while(a[i]<p && i<=end);
        do{
            j--;
            count++;
        }while(a[j]>p && j>=beg);
        swap(a[i],a[j]);
    }while(i<j);
    swap(a[i],a[j]);
    swap(a[j],a[beg]);
    return j;
}

void quicksort(int *a,int beg,int end){
    if(beg<end){
        int s=partition(a,beg,end);
        quicksort(a,beg,s-1);
        quicksort(a,s+1,end);
    }
    else{
        return;
    }
}
	
void main()
{
	FILE *b,*w;
	b=fopen("quickbest.txt","w");
	w=fopen("quickworst.txt","w");
	for(int n=10;n<=200;n+=10)
	{
	int* a=(int*)malloc(sizeof(int)*n);
	
	count=0;
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	quicksort(a,0,n-1);
	fprintf(w,"%d\t%d\n",n,count);
	
	count=0;
	for(int i=0;i<n;i++)
	{
		a[i]=10;
	}
	quicksort(a,0,n-1);
	fprintf(b,"%d\t%d\n",n,count);
	}
	fclose(w);
	fclose(b);
}






