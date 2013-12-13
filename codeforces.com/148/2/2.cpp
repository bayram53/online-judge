# include <stdio.h>
# include <algorithm>
# include <string.h>

using namespace std;

int l,r,a=0;
int n,m;
int t[109];
char c;
int g[109];
int ans[109][19];

int main()
{
	scanf("%d %d\n",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%c",&c);
		
		if(c=='>')
			t[h]=-5;
			
		else if(c=='<')
			t[h]=-6;
			
		else
			t[h]=c-48;
	}
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&l,&r);
		
		a=0;
		int k=1,p=0,f=0,a1=0,a2=0;
		
		for(int h1=l-1; h1<r; h1++)
		g[a++]=t[h1];
		
		while(p<a && p>-1 && f<100009)
		{
			f++;
			
			if(g[p]==-1)
			{
				p+=k;
				continue;
			}
		
			if(a1<-1 && a2!=p && g[p]<-1)
			g[a2]=-1;
			
			a1=g[p];
			a2=p;
			if(g[p]>=0)
			{
				ans[h][g[p]]++;
				g[p]--;
				p+=k;
			}
				
			else if(k==1 && g[p]==-5)
				p++;
			
			else if(k==-1 && g[p]==-6)
				p--;
			
			else if((k==1 && g[p]==-6) || (k==-1 && g[p]==-5))
			{
				
				k*=-1;
				p+=k;
			}
		}
	}
	
	for(int h=0; h<m; h++)
	{
		for(int j=0; j<10; j++)
		printf("%d ",ans[h][j]);
		printf("\n");
	}
}
