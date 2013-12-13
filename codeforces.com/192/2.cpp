# include <stdio.h>

int n,m,a,b;

int G[1009][1009] , T[1000009][3];

bool v[1009];

void dfs(int x)
{
	for(int h=1; h<=n; h++)
	if(!G[x][h]  &&  !v[h])
	{
		v[h] = 1;
		T[a][0] = x;
		T[a++][1] = h;
		dfs(h);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		G[b][a] = G[a][b] = 1;
	}
	
	for(int h=1; h<=n; h++)
	{
		bool p = 0;
		
		for(int j=1; j<=n; j++)	if(G[h][j]) p = 1;
		
		if(!p)	a = h;
	}
	
	printf("%d\n",n-1);
	
	for(int h=1; h<=n; h++)
		if(a != h)	printf("%d %d\n",a,h);
}
