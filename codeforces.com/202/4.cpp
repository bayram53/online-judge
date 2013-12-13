# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <vector>

# define MAXN 1000009

typedef long long lld;

using namespace std;

int n, a, b, ans;

vector <int> G[MAXN];

lld isleg[MAXN], ch[MAXN], mx = 10000000000009, k, san, val[MAXN];

lld gcd(lld x,lld y)
{
	if(y)	return gcd(y, x%y);
	return x;
}

lld lcm(lld x,lld y)	{return x*y/gcd(x,y);}

void dfs(int cur,int par)
{
	isleg[cur] = 1;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(par == to)	continue;
		
		dfs(to, cur);
		
		ch[cur]++;
		
		lld s = isleg[to]/gcd(isleg[cur], isleg[to]);
		if(mx/s < isleg[cur])	{ans = 1;return;}
		
		isleg[cur] = lcm(isleg[cur], isleg[to]);
	}
	
	if(ch[cur])	isleg[cur] *= ch[cur];
	
	if(isleg[cur] > mx)	ans = 1;
}

int goy(int cur,int par,lld app)
{
	int p = 1;
	
	if(!ch[cur])	san += val[cur] - app;
	
	if(!ch[cur]  &&  app > val[cur])	return 0;
	
	for(int h=0; h<(int)G[cur].size(); h++)
	{
		int to = G[cur][h];
		
		if(par == to)	continue;
		
		if(!goy(to, cur, app/ch[cur]))	p = 0;
	}
	
	return p;
}

int b_s(lld l,lld r)
{
	if(r-l < 2)
	{
		if(goy(1, -1, isleg[1]*r))	return r;
		if(goy(1, -1, isleg[1]*l))	return l;
		return 0;
	}
	
	lld mid = (l+r)/2;
	
	if(goy(1, -1, isleg[1]*mid))	return b_s(mid, r);
	
	return b_s(l, mid);
}

int main()
{
	cin>>n;
	
	for(int h=1; h<=n; h++)	cin>>val[h], k += val[h];
	
	for(int h=0; h<n-1; h++)
	{
		cin>>a>>b;
		
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1, -1);
	
	if(ans)	{cout<<k;return 0;}
	
	lld f = b_s(1, mx/isleg[1]);
	
	san = 0;
	
	goy(1, -1, isleg[1]*f);
	
	cout<<san;
}
