# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

struct mal
{
	int a,b,c;
};

int function (void const *x,void const *y)
{
	mal m=*(mal*)x;
	mal n=*(mal*)y;
	
	return m.a-n.a;
}

bool vis[100][100];
bool f[100][100];

int n,s=0,p=0,ans=0;
int o[100][100];
int t[109];
mal g[109]; 
mal l[109];
int d[109];
mal l1[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&t[h]);
		s+=t[h];
		d[h+1]=t[h];
	}
	
	for(int h=1; h<n; h++)
		d[h]+=d[h-1];
	
	for(int h=0; h<n; h++)
		for(int j=0; j<t[h]; j++)
		{
			scanf("%d",&g[p].a);
			
			g[p].b=h+1;
			g[p].c=j+1;
			l[p].b=h+1;
			l[p].c=j+1;
			l[p].a=g[p].a;
			l1[p].b=h+1;
			l1[p].c=j+1;
			l1[p].a=g[p].a;
			p++;
		}
		
		qsort(g,s,sizeof(mal),function);
		
		p=0;
		
		for(int h=0; h<n; h++)
			for(int j=0; j<t[h]; j++)
			{
				if((g[p].b!=l[p].b || g[p].c!=l[p].c) && vis[g[p].b][g[p].c]==0)
				{
					ans++;
					l[d[h]+j].b=g[p].b;
					l[d[h]+j].c=g[p].c;
					vis[g[p].b][g[p].c]=1;
				}
				p++;
			}
	
	printf("%d\n",ans);
	p=0;
	for(int h=0; h<n; h++)
			for(int j=0; j<t[h]; j++)
			{
				if((g[p].b!=l1[p].b || g[p].c!=l1[p].c) && f[g[p].b][g[p].c]==0)
				{
					printf("%d %d %d %d\n",g[p].b,g[p].c,l1[p].b,l1[p].c);
					
					l1[d[h]+j].b=g[p].b;
					l1[d[h]+j].c=g[p].c;
					vis[g[p].b][g[p].c]=1;
					f[g[p].b][g[p].c]=1;
				}
				p++;
			}
		
}
