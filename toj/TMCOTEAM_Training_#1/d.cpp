# include <stdio.h>
# include <string.h>

# define MAXN 1009

struct mal{
	int mx, x, y;
};

int c, r, t;
char s[MAXN][MAXN];
int q[MAXN*MAXN][3] ,G[MAXN][MAXN];
int xd[] = {0, 0, -1, 1};
int yd[] = {-1, 1, 0, 0};

mal bfs(int a,int b)
{
	int x = 0, y = 1;
	mal ret;
	ret.mx = 0, ret.x = a, ret.y = b;
	
	memset(G, -1, sizeof(G));
	G[a][b] = 0;
	
	q[0][0] = a;
	q[0][1] = b;
	
	while(x<y)
	{
		for(int i=0; i<4; i++)
		{
			int tox = q[x][0] + xd[i];
			int toy = q[x][1] + yd[i];
			
			if(tox >= r  ||  tox < 0  ||  toy >= c  ||  toy < 0  ||  G[tox][toy] != -1  ||  s[tox][toy] == '#')	continue;
			
			G[tox][toy] = G[q[x][0]][q[x][1]] + 1;
			
			if(G[tox][toy] > ret.mx)	ret.mx = G[tox][toy], ret.x = tox, ret.y = toy;
			
			q[y][0] = tox;
			q[y++][1] = toy;
		}
		
		x++;
	}
	
	return ret;
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&c,&r);
		
		for(int i=0; i<r; i++)	scanf("%s",s[i]);
		
		/// find free block()
		int x = 0, y = 0;
		
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				if(s[i][j] == '.')
					x = i, y = j;
		
		mal tmp = bfs(x, y);
		
		printf("Maximum rope length is %d.\n",bfs(tmp.x,tmp.y).mx);
	}
}
