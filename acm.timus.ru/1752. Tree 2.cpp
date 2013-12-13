# include <stdio.h>
# include <vector>
# include <algorithm>

# define MAXN 20009

using namespace std;

int n,a,b,q;

vector <int> G[MAXN];

int T[MAXN] , L[MAXN] , D[MAXN][3][3] , P[MAXN][30];

void dfs0(int cur,int prev)
{
	if(prev != -1)	L[cur] = L[prev]+1;
	P[cur][0] = T[cur] = prev;
	D[cur][0][0] = cur;
	D[cur][0][2] = -1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int nxt = G[cur][h];
		
		if(nxt == prev)	continue;
		
		dfs0(nxt,cur);
		
		if(D[cur][0][1] <= D[nxt][0][1]+1)	swap(D[cur][0],D[cur][1]) , D[cur][0][0] = D[nxt][0][0] , D[cur][0][1] = D[nxt][0][1]+1;
		
		else if(D[cur][1][1] < D[nxt][0][1]+1)	D[cur][1][0] = D[nxt][0][0] , D[cur][1][1] = D[nxt][0][1]+1;
	}
}

void dfs1(int cur,int prev)
{
	if(prev != -1)
	{
		int best = 0;
		
		if(D[prev][0][0] == D[cur][0][0])	best++;
		
		if(D[cur][0][1] <= D[prev][best][1]+1)	swap(D[cur][0] , D[cur][1]) , D[cur][0][0] = D[prev][best][0] ,
			D[cur][0][1] = D[prev][best][1]+1;
		
		else if(D[cur][1][1] < D[prev][best][1]+1)	D[cur][1][0]  = D[prev][best][0] , D[cur][1][1] = D[prev][best][1]+1;
	}
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int nxt = G[cur][h];
		
		if(nxt == prev)	continue;
		
		dfs1(nxt,cur);
	}
}

int go_up(int node,int x)
{
	int e = 0;
	
	for(int h=20; h>-1; h--)
		if(e + (1<<h) <= x)
			e += 1<<h , node = P[node][h];
	
	return node;
}

int main()
{
	scanf("%d %d",&n,&q);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs0(1,-1);
	dfs1(1,-1);
	
	//for(int h=1; h<=n; h++)	printf("%d  ==>  (%d , %d , %d)\n",h,D[h][0][0],D[h][0][1],D[h][0][2]);
	
	for(int j=1; (1<<j) < n; j++)
		for(int h=1; h<=n; h++)
			if(P[h][j-1] != -1)
				P[h][j] = P[P[h][j-1]][j-1];
	
	for(int h=0; h<q; h++)
	{
		scanf("%d %d",&a,&b);
		
		if(D[a][0][1] < b)	printf("0\n");
		else if(L[a] >= b)	printf("%d\n",go_up(a,b));
		else 	printf("%d\n",go_up(D[a][0][0],D[a][0][1]-b));
	}
}
