# include <stdio.h>
# include <vector>
# include <algorithm>
# include <math.h>

# define mi(x,y) (x<y ? x : y)

using namespace std;

//#pragma comment(linker, "/STACK:16777216")

int n,a,b,c,e1,root,mal;

vector < vector < pair <int,int> > > G(50009);

int L[50009],H[50009],E[100009],S[50009],P[100009][20];

bool vis[50009];

void dfs(int node,int level)
{
	E[e1++] = node;
	H[node] = e1-1;
	
	vis[node] = 1;
	
	for(int h=0; h<(int)G[node].size(); h++)
		if(!vis[G[node][h].first])
		{
			a = G[node][h].first;
			b = G[node][h].second;
			
			L[a] = level+1;
			S[a] = S[node] + b;
			
			dfs(a,level+1);
			
			E[e1++] = node;
		}
}

int LCA(int x,int y)
{
	int nr = (int)log2(y-x+1);
	
	if(L[P[x][nr]] < L[P[y+1-(1<<nr)][nr]])	return P[x][nr];
	
	return P[y+1-(1<<nr)][nr];
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a++,b++;
		G[b].push_back(make_pair(a,c));
		G[a].push_back(make_pair(b,c));
	}
	
	L[1] = 1;
	
	dfs(1,1);
	
	for(int h=0; h<e1; h++)	P[h][0] = E[h];
	
	for(int h=1; (1<<h)<e1; h++)
		for(int j=0; j+(1<<h)-1<e1; j++)
		{
			if(L[P[j][h-1]] < L[P[j+(1<<(h-1))][h-1]])	P[j][h] = P[j][h-1];
			else 	P[j][h] = P[j+(1<<(h-1))][h-1];
		}
	
	//for(int h=0; h<e1; h++)	printf("%d ",E[h]);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
	
		a++,b++;
	
		if(H[a] > H[b])	swap(a,b);
	
		printf("%d\n",S[a]+S[b]-2*S[LCA(H[a],H[b])]);
	}
}
