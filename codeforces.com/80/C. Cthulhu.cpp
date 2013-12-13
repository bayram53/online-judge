# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>

# define MAXN 109
# define ma(x,y) (x>y ? x : y)
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n,m,a,b,k,p;

vector <int> G[MAXN];

int tin[MAXN],tout[MAXN],timer;

bool v[MAXN];

bool most[MAXN][MAXN];

void dfs(int cur,int prev)
{
	tout[cur] = tin[cur] = timer++;
	v[cur] = 1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(prev == to)	continue;
		
		if(v[to])	tout[cur] = mi(tin[to] , tout[cur]);
		
		else
		{
			dfs(to,cur);
			tout[cur] = mi(tout[to] , tout[cur]);
			
			if(tin[cur] < tout[to])	most[to][cur] = most[cur][to] = 1;
		}
	}
}

void dfs1(int cur,int prev)
{
	v[cur] = 1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(most[cur][to])	continue;
		
		if(prev == to)	continue;
		
		if(v[to])	k++;
		
		else dfs1(to,cur);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1,-1);
	
	/*for(int h=1; h<=n; h++)
	{
		for(int j=1; j<=n; j++)printf("%d ",most[h][j]);
		printf("\n");
	}*/
	
	for(int h=1; h<=n; h++)
		if(!v[h])	k++;
	
	if(k){printf("NO");return 0;}
	
	memset(v , 0 , sizeof(v));
	
	for(int h=1; h<=n; h++)
		if(!v[h])
		{
			k = 0;
			dfs1(h,-1);
			
			if(k > 2){printf("NO");return 0;}
			
			if(k)	p++;
		}
	
	if(p != 1)	printf("NO");
	else printf("FHTAGN!");
}
