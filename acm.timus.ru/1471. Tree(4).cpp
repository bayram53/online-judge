#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
 
const int V = 50009;
vector< pair<int,int> > adj[V];     // adjacency list
int parent[V], heavy[V], dist[V];
int depth[V], size[V];  
int chain[V], head[V];  
//Where chain[u] is u's chain number and head[u] is the node closest to root in u's chain.
 
void DFS(int i)
{
    size[i] = 1;
    for (int k=0; k<(int)adj[i].size(); ++k)
    {
        int j = adj[i][k].first;
        if (j == parent[i]) continue;
 
        parent[j] = i;
        depth[j] = depth[i] + 1;
        dist[j] = dist[i] + adj[i][k].second;
 
        DFS(j);
 
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]]) 
            heavy[i] = j;
    }
}
 
void heavylight_DFS(int N)
{
    memset(heavy, -1, sizeof(heavy));
 
    parent[1] = -1;
    DFS(1);
 
    int c = 0;  
    for (int i=1; i<=N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i;
            c++;
        }
}
  
int lca_1(int i, int j)
{
    while (chain[i] != chain[j])
    {
        if (depth[head[i]] > depth[head[j]])
            i = parent[head[i]];
        else
            j = parent[head[j]];
	}
	
    return depth[i] < depth[j] ? i : j;
}
 
int lca_2(int i, int j)
{
    while (chain[i] != chain[j])
    {
        if (depth[head[i]] > depth[head[j]])
            swap(i, j);
        j = parent[head[j]];
    }
 
    if (depth[i] > depth[j])
        swap(i, j);
    return i;
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
}
 
int main()
{
	
	int N, i, j, k, Q;
 
	scanf("%d", &N);
	
	for(int h=0; h<N-1; h++)
	{
		scanf("%d %d %d",&i,&j,&k);
		i++;j++;
		adj[i].push_back(make_pair(j,k));
		adj[j].push_back(make_pair(i,k)); 
	}
 
	heavylight_DFS(N);
 
	//printf("%d\n", lca_2(12, 16));
 
	//printf("%d\n", lca_2(16, 12));
 
	//printf("%d\n", lca_2(0, 7));
 
	//printf("%d\n", lca_2(0, 24));
 
	//printf("%d\n", lca_1(6635, 8590));
 
	//look_inside(N); //I just added it into this program in order to understand more about how it works
	
	scanf("%d",&Q);
	
	for(int h=0; h<Q; h++)
	{
		scanf("%d %d",&i,&j);
		i++,j++;
		printf("%d\n",dist[i] + dist[j] - 2*dist[lca_1(i,j)]);
	}
}
/*
13
1 2 1
1 3 1
1 4 1
3 5 1
3 6 1
3 7 1
6 8 1
6 9 1
7 10 1
7 11 1
10 12 1
10 13 1
*/
