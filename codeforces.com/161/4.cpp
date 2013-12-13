# include <stdio.h>
# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

int n,m,k,a,b,ti=0;
vector < vector <int> > t(100009);
int tin[100009];
bool v[100009];
int ans[100009],d=0;

int tap(int x,int y=-1)
{
	ti++;
	v[x]=1;
	tin[x]=ti;
	
	for(int h=0; h<(int)t[x].size(); h++)
	{
		int to=t[x][h];
		
		if(y==to)
			continue;
		
		if(v[to]==1)
		{
			if(ti-tin[to]+1>k)
				{ans[d++]=x;return to;}
		}
		
		else
		{
			int g=tap(to,x);
			
			if(g==0 || g==x)
			{
				if(g==x)
					ans[d++]=x;
				
				return 0;
			}
			
			ans[d++]=x;
				
			return g;
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	tap(1);
	printf("%d\n",d);
	for(int h=d-1; h>-1; h--)
		printf("%d ",ans[h]);
}
