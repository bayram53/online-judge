//By Lin
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
#define Rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int        ecnt;
struct    Edge{
    int to;
    Edge *next;
}*mat[N],edges[N*2];
void    link(int x,int to){
    edges[ecnt].to = to;
    edges[ecnt].next = mat[x];
    mat[x] = &edges[ecnt++];
}
void    check(int &x,int y){
    if ( x == -1 || y < x ) x = y;
}

int        n,m;
int        size[N],son[N],fa[N],dev[N],dn[N],id[N];
int        tp[N],in_tree[N],cnt;
void    dfs1(int x,int father){
    size[x] = 1;
    son[x] = -1;
    for ( Edge *p = mat[x]; p; p = p->next ){
        int to = p->to;
        if ( to == father ) continue;
        dfs1(to,x);
        fa[to] = x;
        dev[to] = dev[x]+1;
        size[x] += size[to];
        if ( son[x] == -1 || size[son[x]]<size[to] ) son[x] = to;
    }
}
int        dfs2(int x,int father,int top){
    id[in_tree[x] = ++cnt] = x;
    tp[x] = top;
    if ( son[x] == -1 ) return dn[x]=x;
    dn[x] = dfs2(son[x],x,top);
    for ( Edge *p = mat[x]; p; p = p->next ){
        int to = p->to;
        if ( to == father || to == son[x] ) continue;
        dfs2(to,x,to);
    }
    return dn[x];
}


int        in_stack[N],key[N],nn[N];
vector<int>    stack[N];

void    stack_swap( int k , int x,int y){
    swap(stack[k][x],stack[k][y]);
    in_stack[ stack[k][x] ] = x;
    in_stack[ stack[k][y] ] = y;
}
//x<y
bool    cmp(int x,int y){
    if ( x == y ) return false;
    if ( x == -1 ) return false;
    if ( y == -1 ) return true;
    return x<y;
}

void    stack_up( int k , int x ){
    int    n = nn[k];
    while ( x > 1 ){
        if ( !cmp( key[stack[k][x]] , key[stack[k][x/2]]) )  break;
        stack_swap(k , x , x/2 );
        x /= 2; 
    }
}

void    stack_down( int k , int x ){
    int    n = nn[k];
    while ( 2*x <= n ){
        int t = 2*x;
        if ( t<n && cmp( key[stack[k][t+1]] , key[stack[k][t]] ) ) t++;
        if ( !cmp( key[stack[k][t]] , key[stack[k][x]] ) ) break;
        stack_swap(k , x , t );
        x = t;
    }
}

bool    mark[N];
struct    Segtree{
    int     left[N*4],right[N*4],L[N*4],R[N*4];
    void    build(int l,int r,int step){
        left[step] = l , right[step] = r;
        L[step] = R[step] = -1;
        if ( l == r ) return;
        int mid = ( l + r )/2;
        build( l , mid , step*2 );
        build(mid+1, r , step*2+1);
    }
    void    updata(int w,int step){
        if ( left[step] == right[step] ) {
            L[step] = R[step] = mark[id[w]]?0:(nn[id[w]]?key[stack[id[w]][1]]:-1);
            return;
        }
        int    mid = ( left[step] + right[step] )/2;
        updata( w , step*2+(w>mid) );
        L[step] = L[step*2];
        if ( L[step*2+1] != -1 ) check( L[step] , L[step*2+1]+mid-left[step]+1 );
        R[step] = R[step*2+1];
        if ( R[step*2]   != -1 ) check( R[step] , R[step*2]+right[step]-mid );
    }
    int        ask(int w , int l ,int r,int step ){
        int    mid = ( left[step] + right[step] )/2;
        if ( left[step] == l && right[step] == r ) {
            if ( w <= l ) return L[step]==-1?-1:(L[step]+l-w);
            if ( w >= r ) return R[step]==-1?-1:(R[step]+w-r);
        }
        if ( r <= mid ) return ask( w, l, r , step*2 );
        else if ( mid < l ) return ask( w , l , r , step*2+1 );
        else{
            int ret = ask(w,l,mid,step*2), k = ask(w,mid+1,r,step*2+1);
            if ( k != -1 ) check( ret , ask(w,mid+1,r,step*2+1) );
            return ret;
        }
    }
}tree;

int        main(){
    int    x,y;
    scanf("%d %d", &n ,&m);
    Rep(i,n-1){
        scanf("%d%d", &x, &y );
        link( x , y );
        link( y , x );
    }
    dfs1(1,-1);
    dfs2(1,-1,1);
    memset( nn , 0 , sizeof(nn) );
    memset( key ,-1, sizeof(key));
    memset(mark, 0 , sizeof(mark));
    tree.build(1,n,1);
    for (int i = 1; i<=n; i++) stack[i].push_back(0);
    for (int i = 2; i<=n; i++) 
        if ( tp[i] == i ) {
            stack[fa[i]].push_back(i);
            in_stack[i] = ++nn[fa[i]];
        }
    int    kind , v = 1;
mark[v] ^= 1;
            for ( ; v ; v = fa[v] ) {
                tree.updata( in_tree[v] , 1 );
                v = tp[v];
                int now = tree.ask( in_tree[v] , in_tree[v] , in_tree[dn[v]] , 1 );
                if ( now != -1 ) now++;
                int last = key[v], g =mark[v]?0:(nn[v]?key[stack[v][1]]:-1) ;
                key[v] = now;
                if ( fa[v] ) {
//                    if ( cmp(now,key[v]) ) 
                    stack_up( fa[v] , in_stack[v] );
//                    if ( cmp(key[v],now) ) 
                    stack_down( fa[v] , in_stack[v] );
                }
            }
    while ( m -- ) {
        scanf("%d%d", &kind , &v );
        if ( kind == 1 ) {
            mark[v] ^= 1;
            for ( ; v ; v = fa[v] ) {
                tree.updata( in_tree[v] , 1 );
                v = tp[v];
                int now = tree.ask( in_tree[v] , in_tree[v] , in_tree[dn[v]] , 1 );
                if ( now != -1 ) now++;
                int last = key[v], g =mark[v]?0:(nn[v]?key[stack[v][1]]:-1) ;
                key[v] = now;
                if ( fa[v] ) {
//                    if ( cmp(now,key[v]) ) 
                    stack_up( fa[v] , in_stack[v] );
//                    if ( cmp(key[v],now) ) 
                    stack_down( fa[v] , in_stack[v] );
                }
            }
        }
        else {
            int    ans = -1;
            for (int length = 0; v ; v = fa[tp[v]] ){
                int k = tree.ask(in_tree[v],in_tree[tp[v]],in_tree[dn[v]],1);
                if ( k != -1 )
                    check( ans , k+length );
                length += in_tree[v]-in_tree[tp[v]]+1;
                if ( ans != -1 && length > ans ) break;
            }
            printf("%d\n" , ans );
        }
    }
    return 0;
}

