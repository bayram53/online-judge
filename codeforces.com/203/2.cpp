# include <stdio.h>
# include <algorithm>
# include <vector>

# define MAXN 100009

using namespace std;

int n, ans, st, hot;

int G[MAXN], path[MAXN], fin[MAXN];

int v[MAXN], vis[MAXN];

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
	{
		scanf("%d",&v[h]);
		if(v[h])	hot = h;
	}
		
	for(int h=1; h<=n; h++)
	{
		int a;
		scanf("%d",&a);
		
		if(G[a])	G[a] = -1;
		else 	G[a] = h;
		
	}
	
	//for(int h=1; h<=n; h++)	printf("__%d\n",G[h]);	printf("\n");
	
	for(int h=1; h<=n; h++)
		if(!vis[h]  &&  G[h] > 0)
		{
			int a = h, p = 0;
			vector <int> pl;
			
			while(G[a] > 0)
			{
				if(vis[a]){	p += path[a]; a = fin[a]; break;}
				else 	pl.push_back(a), vis[a] = 1, p++, a = G[a];
			}
			
			for(int j=0; j<(int)pl.size(); j++)	fin[pl[j]] = a, path[pl[j]] = p - j;
			
			if(ans < path[h]  &&  v[fin[h]])	ans = path[h], st = h;
		}
	
	if(ans)
	{
		printf("%d\n",ans+1);
		
		while(G[st] > 0)	{printf("%d ",st); st = G[st];}
		printf("%d",st);
	}
	
	else 	printf("1\n%d",hot);
}
