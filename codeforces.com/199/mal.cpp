#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <memory.h>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>
	
using namespace std;

/* Constants begin */
const long long inf = 1e18+7;
const long long mod = 1e9+7;
const double eps = 1e-12;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0;(i)<(ll)(n);(i)++)
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

int n, m;

vector<int> g[100005];

int ans[100005], val[100005], q[500005], qt, qh;
int par[100005][30], in[100005], out[100005], timer;
int tdist[100005];

void dfs(int v, int pr = 0){
	par[v][0] = pr;
	in[v] = timer++;
	
	for(int i=1;i<25;i++)	par[v][i] = par[par[v][i-1]][i-1];
	
	forn(i,g[v].size())
	{
		int to = g[v][i];
		
		if(to == pr) continue;
		
		val[to] = val[v] + 1;
		
		dfs(to,v);
	}
	
	out[v] = timer++;
}

int line(int a, int b){
	return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b){
	if(line(a,b)) return a;
	if(line(b,a)) return b;
	
	for(int i=24;i>=0;i--)	if(!line(par[a][i],b)) a = par[a][i];
	
	return par[a][0];
}

int dist(int a, int b){
	int c = lca(a,b);
	return val[a] + val[b] - 2 * val[c];
}

void bfs(vector<int> ver){
	qh = qt = 0;
	
	memset(tdist,-1,sizeof(tdist));
	
	forn(i,ver.size()) q[qt++] = ver[i], tdist[ver[i]] = 0;
	
	while(qh != qt)
	{
		int v = q[qh++];
		
		forn(i,g[v].size())
		{
			int to = g[v][i];
			
			if(tdist[to] == -1)
			{
				tdist[to] = tdist[v] + 1;
				q[qt++] = to;
			}
		}
	}
	
	forn(i,n) if(tdist[i] != -1) ans[i] = min(ans[i],tdist[i]);
}

int main(void)
{
	scanf("%d%d",&n,&m);
	
	forn(i,n-1)
	{
		int a, b; scanf("%d%d",&a,&b); a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	
	forn(i,n) ans[i] = mod;
	
	dfs(0);
	
	vector<int> now;
	
	now.pb(0);
	
	for(int i=1;i<=m;i++)
	{
		int type, ver;
		
		scanf("%d%d",&type,&ver); ver--;
		
		if(type == 1)	now.pb(ver);
		
		else
		{
			int res = ans[ver];
			
			forn(j,now.size())
				res = min(res,dist(ver,now[j]));
			
			printf("%d\n",res);
		}
		
		if(i % 300 == 0)
		{
			bfs(now);
			now.clear();
		}
	}
	return 0;
}
