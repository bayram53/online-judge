# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>

# define MAXN 209
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

using namespace std;

int n,a,b,k,ans,e;

vector <int> G[MAXN];

int P[MAXN][11] , L[MAXN] , T[MAXN] , D[MAXN][3];

bool v[MAXN];

void dfsa(int cur,int prev)
{
	P[cur][0] = T[cur] = prev;
	if(prev != -1)	L[cur] = L[prev]+1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
		if(prev != G[cur][h])	dfsa(G[cur][h],cur);
}

int lca(int a,int b)
{
	if(L[a] < L[b])	swap(a,b);
	
	for(int h=9; h>-1; h--)
		if(L[a]-(1<<h) >= L[b])
			a = P[a][h];
	
	if(a == b)	return a;
	
	for(int h=9; h>-1; h--)
		if(P[a][h] != -1  &&  P[a][h] != P[b][h])
			a = P[a][h] , b = P[b][h];
	
	return T[a];
}

void dfs(int node)
{
	D[node][0] = D[node][1] = 0;
	
	v[node] = 1;
	
	for(int h=0; h<(int)G[node].size(); h++)
	{
		int to = G[node][h];
		
		if(v[to])	continue;
		
		dfs(to);
		
		if(D[to][0]+1 > D[node][0])	swap(D[node][0] , D[node][1]) , D[node][0] = D[to][0]+1;
		
		else if(D[to][0]+1 > D[node][1])	D[node][1] = D[to][0]+1;
	}
	
	e = ma(e , D[node][0]+D[node][1]);
}

int main()
{
	memset(P  , -1 , sizeof(P));
	
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	L[1] = 1;
	
	dfsa(1,-1);
	
	for(int j=1; (1<<j)<n; j++)
		for(int h=1; h<=n; h++)
			if(P[h][j-1] != -1)
				P[h][j] = P[P[h][j-1]][j-1];
	
	for(int h=1; h<=n; h++)
		for(int j=h+1; j<=n; j++)
		{
			memset(v , 0 , sizeof(v));
			
			k = lca(h,j);
			a = h;
			e = 0;
			
			while(1){v[a] = 1;  if(k == a) break; a = T[a];} a = j;
			while(1){v[a] = 1;  if(k == a) break; a = T[a];}
			
			for(int i=1; i<=n; i++)	if(!v[i])	dfs(i);
			
			ans = ma(ans , e*(L[h]+L[j]-2*L[k]));
		}
		
	printf("%d\n",ans);
}
