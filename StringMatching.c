#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int StringMatching(int n,int m,char* t,char* p)
{
	int i,j;
	for(i=0;i<=n-m;i++)
	{
		j=0;
		while(j<m && t[i+j]==p[j])
		{
			j++;
		}
		if(j==m)
		{
			break;
		}		
	}
		if(i>n-m && j!=m) 
		{
			printf("Pattern NOT found\n");
			return -1;
		}
		return i;
		
}*/

int StringMatching(int n,int m,char* t,char* p)
{
	int count=0;
	int i,j;
	for(i=0;i<=n-m;i++)
	{
		j=0;
		while(j<m && t[i+j]==p[j])
		{
			count++;
			j++;
		}
		if(j==m)
		{
			return count;
		}		
	}
		
		return count;
		
}

void main()
{
	FILE *b,*w;
	b=fopen("stringbest.txt","w");
	w=fopen("stringworst.txt","w");
 char text[1000],*pattern;
 int n=1000,count;
 for(int i=0;i<n;i++)
 {
 	text[i]='a';
 }
 for(int m=100;m<=n;m+=100)
 {
 	pattern=(char*)malloc(sizeof(char)*m);
 	
 	//Best case
 	count=0;
 	for(int i=0;i<m;i++)
 	{
 		pattern[i]='a';
 	}
 	count=StringMatching(n,m,text,pattern);
 	fprintf(b,"%d\t%d\n",m,count);
 	
 	//Worst case
 	count=0;
 	pattern[m-1]='b';
 	count=StringMatching(n,m,text,pattern);
 	fprintf(w,"%d\t%d\n",m,count);
 	
 	free(pattern);
 }
 
 fclose(w);
	fclose(b);
 /*int i;
 scanf("%s",text);
 scanf("%s",pattern);
 i=StringMatching(strlen(text),strlen(pattern),text,pattern);
 if(i!=-1)
 printf("%d\n",i);*/
}
