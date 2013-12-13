# include <stdio.h>
# include <vector>
# include <algorithm>
# include <string.h>

# define MAXN 100009

using namespace std;

int n,a,b,k;

vector < pair <int,int> > G[MAXN];
vector <int> S[MAXN];

int L[MAXN] , P[MAXN][30] , T[MAXN][3] , F[MAXN] , A[MAXN];

void dfs(int cur,int prev)
{
	P[cur][0] = prev;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h].first;
		
		if(prev == to)	continue;
		
		L[to] = L[cur]+1;
		S[L[to]].push_back(to);
		T[to][0] = cur;
		T[to][1] = G[cur][h].second;
		
		dfs(to,cur);
	}
	
}

int lca(int x,int y)
{
	if(L[x] < L[y])	swap(x,y);
	
	for(int h=17; h>-1; h--)
		if(L[x]-(1<<h) >= L[y])
			x = P[x][h];
	
	if(x == y)	return x;
	
	for(int h=17; h>-1; h--)
		if(P[x][h] != -1  &&  P[x][h] != P[y][h])
			x = P[x][h] , y = P[y][h];
	
	return T[x][0];
}

int main()
{
	memset(P , -1 , sizeof(P));
	
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(make_pair(b,h+1));
		G[b].push_back(make_pair(a,h+1));
	}
	
	L[1] = 1;
	dfs(1,-1);
	
	for(int j=1; 1<<j<n; j++)
		for(int h=1; h<=n; h++)
		{
			if(P[h][j-1] != -1)
				P[h][j] = P[P[h][j-1]][j-1];
		}
	
	scanf("%d",&k);
	
	for(int h=0; h<k; h++)
	{
		scanf("%d %d",&a,&b);
		int r = lca(a,b);
		
		F[b]++;
		F[a]++;
		F[r] -= 2;
		
	}
	
	for(int h=n; h>1; h--)
		for(int j=0; j<(int)S[h].size(); j++)
		{
			int to = S[h][j];
			A[T[to][1]] = F[to];
			F[T[to][0]] += F[to];
		}
	
	for(int h=1; h<n; h++)	printf("%d ",A[h]);
}
