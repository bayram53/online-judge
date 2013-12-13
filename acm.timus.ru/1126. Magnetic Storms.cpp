# include <stdio.h>
# include <algorithm>

using namespace std;

int n,m=0,q=0,l;
int t[25009];
int g[1000000][2];

void add(int x,int y,int z)
{
	int a=y;
	
	g[a][0]=x;
	g[a][1]=z;
	
	while(a!=1 && g[a/2][0]<x)
	{
		swap(g[a/2],g[a]);
		a/=2;
	}
}

void del()
{
	int a=1;
	
	g[1][0]=g[q][0];
	g[q][0]=-1;
	g[1][1]=g[q][1];
	q--;
	
	while(a<=q && max(g[a*2][0],g[a*2+1][0])>g[a][0])
	{
		if(g[a*2][0]>g[a*2+1][0])
			swap(g[a*2],g[a]),a*=2;
		
		else
			swap(g[a*2+1],g[a]),a=a*2+1;
	}
}

int main()
{
	scanf("%d",&n);
	
	while(1)
	{
		scanf("%d",&l);
		
		if(l==-1)
			break;
			
		t[m++]=l;
	}
		
	for(int h=0; h<n; h++)
		add(t[h],++q,h+1);
		
	printf("%d\n",g[1][0]);
		
	for(int h=n; h<m; h++)
	{
		add(t[h],++q,h+1);
		
		while(g[1][1]<=h-n+1)
			del();
		
		printf("%d\n",g[1][0]);
	}
	
}
