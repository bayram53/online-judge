# include <stdio.h>
# include <vector>
# include <algorithm>
# include <math.h>
# include <cmath>

# define MAXN 50009

using namespace std;

typedef long long lld;

int n, q, ti, a;

lld sa[MAXN];

struct mal1
{
	int in, out;
} pos[MAXN];

struct mal2
{
	lld val, tmp;
} T[4*MAXN];

vector <int> G[MAXN];

void dfs(int cur)
{
	pos[cur].in = ++ti;
	
	for(int h=0; h<(int)G[cur].size(); h++)
		dfs(G[cur][h]);
	
	pos[cur].out = ti;
}

void upd(int node,int l,int r)
{
	lld a = (lld)l;
	lld b = (lld)r;
	
	T[node*2].tmp += T[node].tmp;
	T[node*2+1].tmp += T[node].tmp;
	T[node*2].val += T[node].tmp * ((a+b)/2 - a + 1);
	T[node*2+1].val += T[node].tmp * (b - ((a+b)/2+1) + 1);
	T[node].tmp = 0;
}

void add(int x,int y,lld z,int l,int r,int node)
{
	if(x <= l  &&  y >= r)
	{
		T[node].tmp += z;
		T[node].val += ((lld)(r-l+1))*z;
		return;
	}
	
	if(x > r  ||  y < l)	return;
	
	upd(node, l, r);
	
	add(x, y, z, l, (l+r)/2, node*2);
	add(x, y, z, (l+r)/2+1, r, node*2+1);
	
	T[node].val  = T[node*2].val + T[node*2+1].val;
}

lld query(int x,int y,int l,int r,int node)
{
	if(x <= l  &&  y >= r)	return T[node].val;
	
	if(x > r  ||  y < l)	return 0;
	
	upd(node, l, r);
	
	return query(x, y, l, (l+r)/2, node*2) + query(x, y, (l+r)/2+1, r, node*2+1);
}

int main()
{
	scanf("%d %d %lld",&n,&q,&sa[1]);
	
	for(int h=2; h<=n; h++)
	{
		scanf("%d %lld",&a,&sa[h]);
		G[a+1].push_back(h);
	}
	
	dfs(1);
	
	for(int h=1; h<=n; h++)	add(pos[h].in, pos[h].in, sa[h], 1, n, 1);
	
	while(q--)
	{
		lld y, z;
		char type[19];
		
		scanf("%s %d %lld %lld",type,&a,&y,&z);
		
		int f1 = pos[a+1].in;
		int f2 = pos[a+1].out;
		
		lld f = (lld)(f2-f1+1);
		
		if(type[0] == 'e'  &&  query(f1, f1, 1, n, 1) < y)	add(f1, f1, z, 1, n, 1);
		
		if(type[0] == 'd'  &&  query(f1, f2, 1, n, 1)/f < y)	add(f1, f2, z, 1, n, 1);
	}
	
	for(int h=1; h<=n; h++)	printf("%lld\n",query(pos[h].in, pos[h].in, 1, n, 1));
	
	//printf("___%lld\n",query(1, n, 1, n, 1));
}
/*
4 3 1
0 10
0 10
1 10
employee 2 15 1
employee 3 5 1
department 0 10 1
*/
