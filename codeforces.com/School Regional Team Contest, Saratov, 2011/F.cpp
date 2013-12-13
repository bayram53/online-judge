# include <stdio.h>
# include <vector>
# include <algorithm>

# define MAXN 109
# define ma(x,y) (x>y ? x : y)

FILE * fin = fopen("input.txt","r");
FILE * fout = fopen("output.txt","w");

using namespace std;

int n,m,a,b,p,ans;

vector < int > G[MAXN];

int D[MAXN][3][3];

void dfs1(int cur,int prev)
{
	D[cur][0][0] = cur;
	D[cur][1][1] = D[cur][0][1] = 0;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int nxt = G[cur][h];
		
		if(nxt == prev)	continue;
		
		dfs1(nxt,cur);
		
		if(D[nxt][0][1]+1 > D[cur][0][1])	swap(D[cur][0] , D[cur][1]) , D[cur][0][0] = D[nxt][0][0] , D[cur][0][1] = D[nxt][0][1]+1;
		
		else if(D[nxt][0][1]+1 > D[cur][1][1])	D[cur][1][0] = D[nxt][0][0] , D[cur][1][1] = D[nxt][0][1]+1;
	}
	
}

void dfs2(int cur,int prev)
{
	if(prev != -1)
	{
		for(int h=0; h<2; h++)
		{
			a = D[prev][h][0];
			b = D[prev][h][1]+1;
			
			if(D[cur][0][0] != a  &&  D[cur][0][1] < b)	swap(D[cur][0],D[cur][1]) , D[cur][0][0] = a , D[cur][0][1] = b;
			
			else if(D[cur][1][0] != a  &&  D[cur][1][1] < b)	D[cur][1][0] = a , D[cur][1][1] = b;
		}
	}
	
	p = ma(p , D[cur][0][1]);
	
	for(int h=0; h<(int)G[cur].size(); h++)
		if(G[cur][h] != prev)
			dfs2(G[cur][h],cur);
}

int main()
{
	fscanf(fin,"%d",&n);
	
	for(int h=0; h<n; h++)
	{
		fscanf(fin,"%d",&m);
		
		for(int j=1; j<=m; j++)	G[j].resize(0);
		
		for(int j=0; j<m-1; j++)
		{
			fscanf(fin,"%d %d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		p = 0;
		
		dfs1(1,-1);
		dfs2(1,-1);
		
		ans += p;
	}
	
	fprintf(fout,"%d\n",ans);
}
