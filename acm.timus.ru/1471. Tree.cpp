# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>

using namespace std;

//#pragma comment(linker, "/STACK:16777216")

int n,v,k=-1;

int a,b,c;

vector < vector < pair <int,int> > > g(50009);

bool vi[50009];

int d[75009];

bool vis[50009];

int yol[50009];

int siz[50009];

int par[50009];

int anc[50009];

vector < vector < pair <int,int> > > f(50009);

int find_set(int x)
{
	if(par[x] == x)	return x;
	return par[x] = find_set(par[x]);
}

void un(int x,int y)
{
	int a = find_set(x);
	int b = find_set(y);
	
	if(a != b)
	{
		if(siz[a] > siz[b])	siz[a] += siz[b] , par[b] = a;
		
		else 	siz[b] += siz[a] , par[a] = b;
	}
}

void lca(int x)
{
	par[x] = x;
	anc[find_set(x)] = x;
	vis[x]= 1;
	for(int h=0; h<(int)g[x].size(); h++)
	{
		int to = g[x][h].first;
		
		if(vis[to])	continue;
		
		lca(to);
		un(x , to);
		anc[find_set(x)] = x;
	}
	
	vi[x] = 1;
	
	for(int h=0; h<(int)f[x].size(); h++)
		if(vi[f[x][h].first])
		{
			d[f[x][h].second] = yol[x] + yol[f[x][h].first] - yol[anc[find_set(f[x][h].first)]]*2;
			//printf("%d %d == %d\n",x,f[x][h].first,find_set(f[x][h].first));
		}
}

void tap(int x,int y)
{
	for(int h=0; h<(int)g[x].size(); h++)
	if(!vi[g[x][h].first])
	{
		yol[g[x][h].first] = y+g[x][h].second;
		vi[g[x][h].first] = 1;
		tap(g[x][h].first , y+g[x][h].second);
	}
}

int main()
{
	scanf("%d",&v);
	
	for(int h=0; h<v-1; h++)
	{
		scanf("%d %d %d",&a,&b,&c);
		g[b].push_back(make_pair(a,c));
		g[a].push_back(make_pair(b,c));
	}
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		f[a].push_back(make_pair(b,h));
		f[b].push_back(make_pair(a,h));
	}
	
	vi[0] = 1;
	tap(0,0);
	memset(vi , 0 , sizeof(vi));
	lca(0);
	
	//for(int h=0; h<v; h++)	printf("__ %d\n",yol[h]);
	
	for(int h=0; h<n; h++)	printf("%d\n",d[h]);
}
