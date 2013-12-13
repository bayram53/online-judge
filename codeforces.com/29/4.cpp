# include <stdio.h>
# include <vector>
# include <algorithm>
# include <string.h>

using namespace std;

int n,a,b,g;

vector <int> G[309];

bool v[309];

int P[309][19] , D[309] , f[309] , s[609],s1;

void dfs(int cur,int prev)
{
	P[cur][0] = prev;
	
	if(cur != 1  &&  (int)G[cur].size() == 1)	g++;

	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		if(prev == to)	continue;
		
		D[to] = D[cur]+1;
		
		dfs(to,cur);
	}
}

int lca(int x,int y)
{
	if(D[x] < D[y])	swap(x,y);
	
	for(int h=9; h>-1; h--)
		if(D[x]-(1<<h) >= D[y])
			x = P[x][h];
	
	if(x == y)	return x;
	
	for(int h=9; h>-1; h--)
		if(P[x][h] != P[y][h])
			x = P[x][h] , y = P[y][h];
	
	return P[x][0];
}

void tap(int x,int y)
{
	int p = lca(x,y);
	
	while(x != P[p][0]  &&  x != y)
	{
		s[s1++] = x;
		x = P[x][0];
	}
	
	int e[309],e1=0;
	
	while(y != p)
	{
		e[e1++] = y;
		y = P[y][0];
	}
	
	for(int h=e1-1; h>0; h--)	s[s1++] = e[h];
}

int main()
{
	memset(P , -1 , sizeof(P));
	
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1,-1);
	
	for(int h=1; (1<<h)<n; h++)
		for(int j=1; j<=n; j++)
			if(P[j][h-1] != -1)
				P[j][h] = P[P[j][h-1]][h-1];
	
	for(int h=1; h<=g; h++)	scanf("%d",&f[h]);
	
	f[0] = 1;
	f[++g] = 1;
	
	for(int h=1; h<=g; h++)
	{
		tap(f[h-1],f[h]);
		if(s1 > 2*n-2)	{printf("-1"); return 0;}
	}
	
	for(int h=0; h<s1; h++)	printf("%d ",s[h]);	printf("1");
}
