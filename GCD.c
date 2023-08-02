#include<stdio.h>
#include<stdlib.h>
int count;
int euclid(int m,int n)
{
	count=0;
	while(n){
	count++;
	int r=m%n;
	m=n;
	n=r;
	}
	return count;
}

int consec(int m,int n)
{
	int min=(m>n)?n:m;
	count=0;
	while(min)
	{
		count++;
		if(m%min==0)
		{
			count++;
			if(n%min==0)
				return count;
			else min--;
		}
		else min--;
	}
}

int modified(int m,int n)
{
	count=0;
	while(n){
	if(m<n){int temp=m;m=n;n=temp;}
	/*int r=m-n;
	m=n;
	n=r;*/
	m=m-n;
	count++;
	}
	return count;
}

void main()
{
	FILE *e,*m,*c;
	e=fopen("euclid.txt","w");
	m=fopen("mod.txt","w");
	c=fopen("consec.txt","w");
	for(int n=10;n<=100;n=n+10)
	{
		int maxcount=0,mincount=99999;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				count=0;
				count=euclid(i,j);
				if(count>maxcount) maxcount=count;
				if(count<mincount) mincount=count;
			}
		}
		fprintf(e,"%d\t%d\t%d\n",n,maxcount,mincount);
	}
	
	for(int n=10;n<=100;n=n+10)
	{
		int maxcount=0,mincount=99999;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				count=0;
				count=consec(i,j);
				if(count>maxcount) maxcount=count;
				if(count<mincount) mincount=count;
			}
		}
		fprintf(c,"%d\t%d\t%d\n",n,maxcount,mincount);
	}
	
	for(int n=10;n<=100;n=n+10)
	{
		int maxcount=0,mincount=99999;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				count=0;
				count=modified(i,j);
				if(count>maxcount) maxcount=count;
				if(count<mincount) mincount=count;
			}
		}
		fprintf(m,"%d\t%d\t%d\n",n,maxcount,mincount);
	}
	
	
	fclose(e);
	fclose(c);
	fclose(m);
}
