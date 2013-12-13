# include <stdio.h>
# include <functional>
# include <string.h>
# include <queue>
# include <algorithm>
# include <vector>

# define MAXN 1000009

using namespace std;

int n, m, t;
vector < pair<int, int> > G[MAXN], GT[MAXN];
bool vis[MAXN];

int sh(vector< pair<int, int> > G[])
{
	int ret = 0;
	
	priority_queue < pair<int,int> , vector< pair<int, int> >, greater< pair<int,int> > > hp;
	///
	
	memset(vis, 0, sizeof(vis));
	hp.push(make_pair(0, 1));
	
	for(int i=0; i<n; i++)
	{
		while(vis[hp.top().second])	{hp.pop();}
		///printf("(%d,%d)\n",hp.top().second,hp.top().first);getchar();
		
		int node = hp.top().second, dist = hp.top().first;
		
		ret += dist;
		
		vis[node] = 1;
		
		for(int i=0; i<(int)G[node].size(); i++)
			if(!vis[G[node][i].first])
				hp.push(make_pair(dist + G[node][i].second, G[node][i].first));
	}
	
	return ret;
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n,&m);
		
		for(int i=1; i<=n; i++)	G[i].resize(0), GT[i].resize(0);
		
		for(int i=0; i<m; i++)
		{
			int a, b, c;
			
			scanf("%d %d %d",&a,&b,&c);
			
			G[a].push_back(make_pair(b, c));
			GT[b].push_back(make_pair(a, c));
		}
		
		printf("%d\n",sh(G)+sh(GT));
	}
}
