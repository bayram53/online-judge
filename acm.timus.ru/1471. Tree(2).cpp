# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <vector>

using namespace std;

int n,n1,a,b,root,c;

int F[50009],P[50009][30],L[50009],S[50009];

bool vis[1009];

vector < vector < pair <int,int> > > G(50009);

void dfs(int node,int y)
{
	for(int h=0; h<(int)G[node].size(); h++)
		S[G[node][h].first] = S[node]+G[node][h].second , L[G[node][h].first] = y+1 , dfs(G[node][h].first,y+1);
}

int LCA(int x,int y)
{
	if(L[x] < L[y])	swap(x,y);
	
	for(int h=n1; h>-1; h--)
		if(L[x] - (1<<h) >= L[y])
			x = P[x][h];
	
	if(x == y)	return x;
	
	for(int h=n1; h>-1; h--)
		if(P[x][h] != -1  &&  P[x][h] != P[y][h])
			x = P[x][h] , y = P[x][h];
	
	return F[x];
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a++,b++;
		G[b].push_back(make_pair(a,c));
		F[a] = b;
		vis[a] = 1;
		P[a][0] = b;
	}
	
	for(int h=1; h<=n; h++)	if(!vis[h])	root = h;
	
	P[root][0] = root;
	
	n1 = (int)log2(n);
	
	for(int h=1; h<=n; h++)
		for(int j=1; j<=n1; j++)
			P[h][j] = -1;
	
	for(int h=1; h<=n1; h++)
		for(int j=1; j<=n; j++)
			if(P[j][h-1] != -1)
				P[j][h] = P[P[j][h-1]][h-1];
	
	dfs(root,0);
	
	//for(int h=1; h<=n; h++)	printf("%d  ,  %d\n",h,S[h]);
	
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d %d",&a,&b);
		a++; b++;
		printf("%d\n",S[a]+S[b]-2*S[LCA(a,b)]);
	}
}
