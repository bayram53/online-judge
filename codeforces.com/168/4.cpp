# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>

# define MAXN 100009
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

typedef long long llint;

using namespace std;

vector <int> G[MAXN] , L[MAXN];

llint D[MAXN] , F[MAXN][3] , K[MAXN];

int P[MAXN];

int n,a,b;

void dfs(int cur,int prev,int level)
{
	L[level].push_back(cur);
	P[cur] = prev;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int nxt = G[cur][h];
		
		if(prev == nxt)	continue;
		
		dfs(nxt,cur,level+1);
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int h=0; h<n; h++)	cin>>D[h+1];
	
	dfs(1,0,0);
	
	for(int h=n-1; h>-1; h--)
		for(int j=0; j<(int)L[h].size(); j++)
		{
			int to = L[h][j];
			
			D[to] += F[to][0]+F[to][1];
			
			if(D[to] < 0)	F[to][0] -= D[to];
			else 	F[to][1] -= D[to];
			
			F[P[to]][0] = ma(F[P[to]][0] , F[to][0]);
			F[P[to]][1] = mi(F[P[to]][1] , F[to][1]);
		}
	
	cout<<F[0][0]-F[0][1];
}
