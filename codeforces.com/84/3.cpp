# include <stdio.h>
# include <algorithm>
# include <vector>

# define MAXN 100009

typedef long long llint;

using namespace std;

llint ans;

vector < pair <int,bool> > G[MAXN];

int n,a,b,c;

llint D[MAXN][3];

bool islucky(int x)
{
	int p = 1;
	
	while(x)
	{
		if(x % 10 != 4  &&  x % 10 != 7)	p = 0;
		x /= 10;
	}
	
	return p;
}

void dfs1(int cur,int prev)
{
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h].first;
		
		if(prev == to)	continue;
		
		dfs1(to,cur);
		
		D[cur][1] += D[to][1]+1;
		
		if(G[cur][h].second)	D[cur][0] += D[to][1]+1;
		else 	D[cur][0] += D[to][0];
	}
}

void dfs2(int cur,int prev,int x)
{
	if(prev != -1)
	{
		a = D[prev][0] - D[cur][0];
		b = D[prev][1] - D[cur][1];
		
		if(x)	D[cur][0] += b;
		else 	D[cur][0] += a;
		D[cur][1] += b;
	}
	
	ans += D[cur][0]*(D[cur][0]-1);
	
	for(int h=0; h<(int)G[cur].size(); h++)	
		if(G[cur][h].first != prev)
			dfs2(G[cur][h].first,cur,G[cur][h].second);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,islucky(c)));
		G[b].push_back(make_pair(a,islucky(c)));
	}
	
	dfs1(1,-1);
	dfs2(1,-1,0);
	
	printf("%I64d",ans);
}
