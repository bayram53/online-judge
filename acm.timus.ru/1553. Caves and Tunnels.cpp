# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <vector>

# define MAXN 100009
# define ma(x,y) (x>y ? x : y)

///#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long llint;

vector <int> G[MAXN];
vector <llint> tree[MAXN];

int n, a, b, k, q;

int size[MAXN], heavy[MAXN], pos[MAXN], sz[MAXN];
int chain[MAXN], head[MAXN], dad[MAXN], depth[MAXN];
llint val[MAXN];

char c;

void dfs(int i)
{
	size[i] = 1;
	
	for(int h=0; h<(int)G[i].size(); h++)
	{
		int to = G[i][h];
		
		if(dad[i] == to)	continue;
		
		dad[to] = i;
		depth[to] = depth[i] + 1;
		
		dfs(to);
		
		size[i] += size[to];
		
		if(heavy[i] == -1  ||  size[to] > size[heavy[i]])
			heavy[i] = to;
	}
}

void hl_dfs()
{
	memset(heavy, -1, sizeof(heavy));
	dad[1] = -1;
	
	dfs(1);
	
	for(int i=1; i<=n; i++)
		if(dad[i] == -1  ||  heavy[dad[i]] != i)
		{
			int p = 0;
			
			for(int h = i; h != -1; h = heavy[h])
				chain[h] = k , head[h] = i , p++ , pos[h] = p;
			
			sz[k] = p;
			tree[k].resize(4*(p+1));
			k++;
		}
}

void add(int x,llint y,int l,int r,int node,int e)
{
	tree[e][node] = ma(tree[e][node],y);
	
	if(l == r)	return ;
	
	if(x <= (l+r)/2)	add(x, y, l, (l+r)/2, node*2, e);
	
	else 	add(x, y, (l+r)/2+1, r, node*2+1, e);
}

llint query(int x,int y,int l,int r,int node,int e)
{
	if(x <= l  &&  y >= r)	return tree[e][node];
	
	if(x > r  ||  y < l)	return 0;
	
	llint i = query(x, y, l, (l+r)/2, node*2, e);
	llint j = query(x, y, (l+r)/2+1, r, node*2+1, e);
	
	return ma(i, j);
}

llint tap(int i,int j)
{
	llint p = 0;
	
	while(chain[i] != chain[j])
	{
		if(depth[head[i]] > depth[head[j]])	swap(i, j);
		
		p = ma(p, query(1, pos[j], 1, sz[chain[j]], 1, chain[j]));
		
		j = dad[head[j]];
	}
	
	if(depth[i] > depth[j])	swap(i, j);
	//printf("<%d %d>  <%d %d>\n",i,j,pos[i],pos[j]);
	return	ma(p, query(pos[i], pos[j], 1, sz[chain[i]], 1, chain[i]));
}

void look_inside(int N) {
	int i;
 
	printf("\n");
	printf("HEAVY: \n");
	printf("(i, j): i----(heavy edge)----j\n\n");
 
	for (i = 1; i <= N; i++)
		printf("(%d, %d)\n", i, heavy[i]);
	
	printf("\n");
	printf("CHAIN: \n");
	printf("(i, j): Node i is in group (heavy-path group) number j\n\n");
	
	for (i = 1; i <= N; i++)
		printf("(%d, %d)\n", i, chain[i]);
 
	printf("\n");
	printf("HEAD: \n");
	printf("(i, j): Node i goes up all the way to the highest node (j) which is in the same group\n\n");
 
	for (i = 1; i <= N; i++)
		printf("(%d, %d)\n", i, head[i]);
		
	printf("\n");
	printf("Child size: \n");
	printf("(i, j): Node i has j child\n\n");
 
	for (i = 1; i <= N; i++)
		printf("(%d, %d)\n", i, size[i]);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	hl_dfs();
	
	//look_inside(n);
	
	scanf("%d",&q);
	
	for(int i=0; i<q; i++)
	{
		scanf("\n%c",&c);
		
		if(c == 'I')	scanf("%d %d",&a,&b) , add(pos[a], val[a]+(llint)b, 1, sz[chain[a]], 1, chain[a]) , val[a] += (llint)b;
		
		if(c == 'G')	scanf("%d %d",&a,&b) , printf("%lld\n",tap(a,b));
	}
}
