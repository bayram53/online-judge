# include <stdio.h>
# include <algorithm>
# include <vector>
# include <iostream>

# define MAXN 50009
# define MAXK 509
# define mi(x,y) (x<y ? x : y)

typedef long long llint;

using namespace std;

int n,a,b,k;

llint D[MAXN][MAXK],ans;

vector<int> G[MAXN];

void dfs(int cur,int prev)
{
	D[cur][0] = 1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int nxt = G[cur][h];
		
		if(prev == nxt)	continue;
		
		dfs(nxt,cur);
		
		for(int j=0; j<k; j++)	ans += D[nxt][j]*D[cur][k-j-1];
		for(int j=0; j<k; j++)	D[cur][j+1] += D[nxt][j];
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1,-1);
	
	cout<<ans;
}
/*
10 2
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
*/
