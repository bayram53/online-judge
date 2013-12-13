# include <stdio.h>
# include <algorithm>
# include <vector>

# define MAXN 200009

using namespace std;

int n,a,b,ans=MAXN,p;

vector <int> P[MAXN];
vector <int> C[MAXN];

int L[MAXN] , D[MAXN];

int E[MAXN],e;

void dfs(int cur,int prev)
{
	if(prev != -1)	L[cur] = L[prev]+1;
	
	for(int h=0; h<(int)C[cur].size(); h++)
	{
		int nxt = C[cur][h];
		
		if(nxt == prev)	continue;
		
		D[nxt] = D[cur];
		
		dfs(nxt,cur);
	}
	
	for(int h=0; h<(int)P[cur].size(); h++)
	{
		int nxt = P[cur][h];
		
		if(nxt == prev)	continue;
		
		D[nxt] = D[cur]+1;	p++;
		
		dfs(nxt,cur);
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		P[b].push_back(a);
		C[a].push_back(b);
	}
	
	dfs(1,-1);
	
	for(int h=1; h<=n; h++)
	{
		int k = p - 2*D[h] + L[h];
		
		if(k < ans)
		{
			ans = k;
			e = 1;
			E[0] = h;
		}
		
		else if(ans == k)	E[e++] = h;
	}
	
	printf("%d\n",ans);
	
	for(int h=0; h<e; h++)	printf("%d ",E[h]);
}
