# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>
# include <limits.h>

# define MAXN 1009
# define INF INT_MAX

using namespace std;

int n, m, q, s, c, e;
vector <int> G[MAXN];
int P[MAXN], S[MAXN], sz;
bool v[MAXN];
struct mal
{
	int head, tail;
	int C[MAXN][3];
} T[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)	scanf("%d",&P[h]);
	
	for(int j=0; j<m; j++)
	{
		scanf("%d %d",&s,&c);
		G[s].push_back(c);
	}
	
	scanf("%d",&q);
	
	while(q--)
	{
		scanf("%d %d %d",&c,&s,&e);
		
		memset(v, 0, sizeof(v));
		
		for(int h=0; h<n; h++)	T[h].head = T[h].tail = 0;
		for(int h=0; h<n; h++)	S[h] = INF;
		
		S[s] = 0;
		T[s].C[T[s].head][0] = P[s];
		T[s].C[T[s].head++][1] = INF-200;
		
		while(1)
		{
			int node, mn = INF;
			for(int h=0; h<n; h++)	if(mn > S[h]  &&  !v[h])	node = h, mn = S[h];
			
			if(mn == INF)	break;
			
			int pes[109], k = 1;
			memset(pes, -1, sizeof(pes));
			pes[0] = 0;
			
			for(int h=T[node].tail; h<T[node].head; h++)
			{
				int i = k+T[node].C[h][1];
				
				if(i > 100)	i = 101;
				
				for(int j=k; j<i; j++)	pes[j] = pes[j-1]+(j-k+1)*T[node].C[h][0];
				
				k = i;
				
				if(k > 100)	break;
			}
			
			for(int h=0; h<(int)G[node].size(); h++)
				if()
		}
	}
}
