# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

int n,asd=0;
char a[109][3][29];
int m=0;
char t[309][29]; 
bool vis[3];
int table[309][309];
char is[]={"Isenbaev"};

void es(char x[],char y[])
{
	int b=strlen(y);
	
	for(int h=0; h<b; h++)
		x[h]=y[h];
}

int main()
{
	
	for(int h=0; h<309; h++)
		for(int j=0; j<309; j++)
			if(j!=h)
				table[h][j]=989;
	
	scanf("%d",&n);
	
	for(int h1=0; h1<n; h1++)
	{
		scanf("%s %s %s",a[h1][0],a[h1][1],a[h1][2]);
		
		for(int h=0; h<m; h++)
			for(int j=0; j<3; j++)
				if(strcmp(a[h1][j],t[h])==0)
					vis[j]=1;
					
		for(int h=0; h<3; h++)
		{
			if(vis[h]==0)
				es(t[m++],a[h1][h]);
			
			vis[h]=0;
		}
	}
	
	
	
	for(int h=0; h<m; h++)
	for(int j=0; j<m; j++)
	if(strcmp(t[h],t[j])==1)
		swap(t[h],t[j]);
	
	for(int s=0; s<n; s++)
	{
		int k[3];
		
		for(int j=0; j<3; j++)
			for(int g=0; g<m; g++)
				if(strcmp(t[g],a[s][j])==0)
					k[j]=g;
		
		for(int h=0; h<3; h++)
			for(int j=0; j<3; j++)
				if(j!=h)
					table[k[h]][k[j]]=1;
	}
	
	for(int h=0; h<m; h++)
		for(int j=0; j<m; j++)
			for(int i=0; i<m; i++)
				if(table[j][h]+table[h][i]<table[j][i] && table[j][h]!=-1 && table[h][i]!=-1 && table[j][i]!=-1)
					table[j][i]=table[j][h]+table[h][i];
	
	for(int h=0; h<m; h++)
		if(strcmp(t[h],is)==0)
		{
			asd++;
			
			for(int j=m-1; j>-1; j--)
			{
				if(table[h][j]!=989)
					printf("%s %d\n",t[j],table[h][j]);
				
				else
					printf("%s undefined\n",t[j]);
			}
			
			break;
		}
		
	if(asd==0)
		for(int h=m-1; h>-1; h--)
			printf("%s undefined\n",t[h]);
}
