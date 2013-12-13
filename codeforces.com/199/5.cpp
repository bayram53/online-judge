# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <vector>
# include <limits.h>
# include <time.h>

# define MAXN 100009
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

time_t st = clock();

//FILE * fin = fopen("in.txt","r");
//FILE * fout = fopen("out.txt","w");

using namespace std;

int n, m, a, b, nr = 316, k, type;

vector <int> G[MAXN];

int ans[MAXN], now[MAXN];

int par[MAXN][30], tdist[MAXN];

int dist[MAXN], queue[MAXN];

bool v[MAXN];

void dfs(int cur)
{
	for(int h=1; h<=16; h++)	if(par[cur][h-1] != -1)	par[cur][h] = par[par[cur][h-1]][h-1];
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(par[cur][0] == to)	continue;
		
		par[to][0] = cur;
		
		dist[to] = dist[cur] + 1;
		
		dfs(to);
	}
}

int lca(int x,int y)
{
	if(dist[x] < dist[y])	swap(x, y);
	
	for(int h=16; h>-1; h--)
		if((1<<h) + dist[y] <= dist[x])
			x = par[x][h];
	
	if(x == y)	return x;
	
	for(int h=16; h>-1; h--)
		if(par[x][h] != par[y][h])
			x = par[x][h], y = par[y][h];
	
	return par[x][0];
}

void bfs()
{
	memset(tdist, -1, sizeof(tdist));
	
	int x = 0, y = k;
	
	for(int h=0; h<k; h++)	tdist[now[h]] = 0, queue[h] = now[h];
	
	while(x < y)
	{
		int cur = queue[x++];
		
		for(int j=0; j<(int)G[cur].size(); j++)
		{
			int to = G[cur][j];
			
			if(tdist[to] == -1)
			{
				tdist[to] = tdist[cur]+1;
				queue[y++] = to;
			}
		}
	}
	
	for(int h=1; h<=n; h++)	if(tdist[h] != -1)	ans[h] = mi(tdist[h], ans[h]);
}

int main()
{
	memset(par, -1, sizeof(par));
	
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1);
	
	for(int h=1; h<=n; h++)	ans[h] = MAXN;
	
	now[k++] = 1;
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&type,&a);
		
		if(type == 1)	now[k++] = a;
		
		else
		{
			int r = ans[a];
			
			for(int j=0; j<k; j++)
			{
				int z = lca(a, now[j]);
				if(dist[a] + dist[now[j]] - 2*dist[z] < 0)	while(1){}
				r = mi(r, dist[a] + dist[now[j]] - 2*dist[z]);
			}
			
			printf("%d\n",r);
		}
		
		if(h%nr == 0)	bfs(), k = 0;
	}
	
	//printf("%lf",(clock()-st)/1000000.0);
}
