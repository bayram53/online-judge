# include <stdio.h>
# include <ctype.h>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

int r,c,xy,yy,xe,ye,ans;

char S[1009][1009];

int d[1000009][3],a,b=1,G[1009][1009];

int x[] = {0 , 0 , -1 , 1};
int y[] = {1 , -1 , 0 , 0};

void dfs()
{
	for(int h=0; h<4; h++)
	{
		int x1 = d[a][0] + x[h];
		int y1 = d[a][1] + y[h];
		
		if(S[x1][y1] == 'E'  ||  S[x1][y1] == 'T'  ||  G[x1][y1]  ||  mi(x1,y1) < 0  ||  x1 >= r  ||  y1 >= c)	continue;
		
		G[x1][y1] = G[d[a][0]][d[a][1]]+1;
		d[b][0] = x1;
		d[b++][1] = y1;
	}
	
	a++;
	
	if(a < b)	dfs();
}

int main()
{
	scanf("%d %d",&r,&c);
	
	for(int h=0; h<r; h++)
	{
		scanf("%s",S[h]);
		
		for(int j=0; j<c; j++)
		{
			if(S[h][j] == 'S')	xy = h , yy = j;
			if(S[h][j] == 'E')	d[0][0] = h , d[0][1] = j;
		}
	}
	
	dfs();
	
	for(int h=0; h<r; h++)	
		for(int j=0; j<c; j++)
			if(G[h][j] <= G[xy][yy]  &&  isdigit(S[h][j])  &&  G[h][j])
				ans += S[h][j] - 48;
	
	printf("%d",ans);
}
