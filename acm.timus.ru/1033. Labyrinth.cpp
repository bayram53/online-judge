# include <stdio.h>

int n,ans;

int x[] = {1 , -1 , 0 , 0};
int y[] = {0 , 0 , 1 , -1};

int s[109][109];

char c[90];

bool vis[109][109];

int g[10009][3];

void tap(int x1,int y1)
{
	int a=1 , b=0;
	
	vis[x1][y1] = 1;
	
	g[0][0] = x1;
	g[0][1] = y1;
	
	while(a > b)
	{
		for(int h=0; h<4; h++)
		{
			int tox = g[b][0] + x[h];
			int toy = g[b][1] + y[h];
			
			if(s[tox][toy]  ||  tox < 1  ||  toy < 1  ||  tox > n  ||  toy > n)	ans++;
			
			else if(!vis[tox][toy])
			{
				vis[tox][toy] = 1;
				g[a][0] = tox;	g[a++][1] = toy;
			}
		}
	
		b++;
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
	{
		scanf("%s",c);
		
		for(int j=1;  j<=n; j++) s[h][j] = (c[j-1] == '#' ? 1 : 0);
		
	}
	
	tap(1,1);
	
	if(!vis[n][n])	tap(n,n);
	
	printf("%d\n",(ans-4)*9);
	
	/*for(int h=1; h<=n; h++)
	{
		for(int j=1; j<=n; j++)	printf("%d",vis[h][j]);
		printf("\n");
	}*/
}
