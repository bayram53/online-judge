#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define FOR(i,a,b) for(i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define INF 1000000000

int up[200300][20],i,j = 0,n,m,lst[500000],a[500000],nxt[500000],yk2,x,sz;
int dist[500000], timer=0, tin[500000], tout[500000], y[500000], ans, e;
int sum[500000], yy;
int o[500000];

void add(int x, int yy) {
  ++j;
  y[j] = yy;
  nxt[j] = lst[x];
  lst[x] = j;
}

void bfs(){
   int yk1 = 0, yk2 = 0;
   for (int i = 0; i < sz; ++i) {
     o[++yk1] = a[i];
   }
   sz = 0;
   while (yk1 > yk2) {
     ++yk2;
     int x = o[yk2];
     j = lst[x];
     while (j) {
         if (dist[y[j]] > dist[x] + 1) {
            dist[y[j]] = dist[x] + 1;
            ++yk1;
            o[yk1] = y[j];
         }
        j = nxt[j];
     }
   }
}


bool upper(int a, int b) {
  if (tin[a] <= tin[b] && tout[a] >= tout[b]) return true; else return false;
}

int lca(int a, int b) {
  if (upper(a,b)) return a;
  if (upper(b,a)) return b;
  for (int i = 18; i >= 0; --i) {
     if (!upper(up[a][i],b)) a = up[a][i];
  }
  return up[a][0];
}

void dfs0(int x, int p) {
  tin[x] = ++timer;
  up[x][0] = p;
  for (int i = 1; i <= 18; ++i) up[x][i] = up[up[x][i-1]][i-1];
  int j = lst[x];
  while (j) {
      if (y[j] != p) {
         sum[y[j]] = sum[x] + 1;
         dfs0(y[j],x);
      }  
     j=nxt[j];
  }
  tout[x] = ++timer;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d", &x, &yy);
        x--; yy--;
        add(x, yy);
        add(yy, x);
    }
    dfs0(0, 0);
    a[0] = 0;
    sz = 1;
    dist[0] = 0;
    for (int i = 1; i < n; ++i) dist[i] = 1000000000;
    for (int i = 0; i < m; ++i) {
      int v, t;
      scanf("%d %d",&t, &v);
      v-=1;
      if (t == 1) {
         a[sz++] = v;
         dist[v]=0;
      }
      else {
         ans=dist[v];
         if (sz>300) {
            bfs();
            sz=0;
         }
         else {
             for (int q=0;q<sz;++q) {
                 int e=lca(v,a[q]);
                 x=sum[v]+sum[a[q]]-2*sum[e];
                 ans=min(ans,x);
             }
         }
         ans=min(ans,dist[v]);
         cout<<ans<<endl;
      }
    }
}
