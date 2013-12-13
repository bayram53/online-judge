# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>

# define MAXN 100009
# define ma(x,y) (x>y : x : y)
# define mi(x,y) (x<y : x : y)

using namespace std;

int n,m,d,a,b,ans;

vector <int> G[MAXN];

bool v[MAXN];

int T[MAXN][5];

void dfs1(int cur,int prev)
{
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(to == prev)	continue;
		
		dfs1(to,cur);
		
		int g = -10;
		
		if(T[to][0])	g = T[to][1]+1;
		
		if(T[cur][1] <= g)	T[cur][2] = T[cur][0] , T[cur][3] = T[cur][1] , T[cur][0] = T[to][0] , T[cur][1] = g;
		
		else if(T[cur][3] <= g)	T[cur][2] = T[to][0] , T[cur][3] = g;
	}
}

void dfs2(int cur,int prev)
{
	if(prev != -1)
	{
		int best = 0;
		
		if(T[cur][0] == T[prev][0])	best = 2;
		
		if(T[prev][best] == 0)	T[prev][best+1] = -10;
		
		if(T[cur][1] <= T[prev][best+1]+1)	T[cur][2] = T[cur][0] , T[cur][3] = T[cur][1] , T[cur][0] = T[prev][best] , T[cur][1] = T[prev][best+1]+1;
	
		else if(T[cur][3] <= T[prev][best+1]+1)	T[cur][2] = T[prev][best] , T[cur][3] = T[prev][best+1]+1;
	}
	
	for(int h=0; h<(int)G[cur].size(); h++)	if(prev != G[cur][h])	dfs2(G[cur][h],cur);
}

int main()
{
	scanf("%d %d %d",&n,&m,&d);
	
	for(int h=0; h<m; h++)	scanf("%d",&a) , v[a] = 1 , T[a][0] = a;
	
	for(int h=1; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs1(1,-1);
	dfs2(1,-1);
	
	//for(int h=1; h<=n; h++)	printf("%d ==>   %d : %d     %d : %d\n",h,T[h][0],T[h][1],T[h][2],T[h][3]);
	
	for(int h=1; h<=n; h++)	if(T[h][1] <= d)	ans++;
	
	printf("%d",ans);
}
