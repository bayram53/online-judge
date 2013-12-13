# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <vector>

# define ma(x,y) (x>y ? x : y)
# define MAXN 10000

using namespace std;

int n, t;
int T[4*MAXN+9], L[MAXN+9];
vector <int> D[MAXN+9];

void upd(int x,int y,int l,int r,int node)
{
	if(l == r)
	{
		T[node] = y;
		return ;
	}
	
	if(x <= (l+r)/2)	upd(x, y, l, (l+r)/2, node*2);
	else 	upd(x, y, (l+r)/2+1, r, node*2+1);
	
	T[node] = ma(T[node*2], T[node*2+1]);
}

int query(int x,int l,int r,int node)
{
	if(x < l)	return 0;
	
	if(x >= r)	return T[node];
	
	int a = query(x, l, (l+r)/2, node*2);
	int b = query(x, (l+r)/2+1, r, node*2+1);
	
	return ma(a, b);
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		memset(T, 0, sizeof(T));
		memset(L, 0, sizeof(L));
		int ans = 0;
		
		scanf("%d",&n);
		
		for(int h=0; h<n; h++)
		{
			int a, b;
			scanf("%d %d",&a,&b);
			D[a].push_back(b);
		}
		
		for(int h=1; h<=MAXN; h++)
		{
			for(int j=0; j<(int)D[h].size(); j++)
			{
				int k = query(D[h][j]-1, 1, MAXN, 1);
				
				L[k]--;
				
				if(!L[k])	upd(k, 0, 1, MAXN, 1);
			}
			
			for(int j=0; j<(int)D[h].size(); j++)	upd(D[h][j], D[h][j], 1, MAXN, 1), L[D[h][j]]++;
			
			D[h].resize(0);
		}
		
		for(int h=1; h<=MAXN; h++)	ans += L[h];
		
		printf("%d\n",ans);
	}
}
/*
4
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
*/
