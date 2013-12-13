# include <stdio.h>
# include <algorithm>

using namespace std;

int n;

int d[3][1009];

bool dp[1009][1009];

int par1[1009] , par2[1009];

bool vis[1009][1009];

char c;

bool tap(int x,int y)
{
	if(vis[x][y])	return dp[x][y];
	
	vis[x][y] = 1;
	
	int p = 0;
	
	if(x)	p += tap(x-1,y);
	if(y)	p += tap(x,y-1);
	
	if(p)	dp[x][y] = 1;
	
	if(abs(x+y-2*(par1[x]+par2[y])) > 1)	dp[x][y] = 0;
	
	return dp[x][y];
}

int main()
{
	scanf("%d\n",&n);
	
	for(int h=1; h<=n; h++)	scanf("%c",&c) , d[0][h] = c-48 , par1[h] = d[0][h] + par1[h-1];scanf("\n");
	for(int h=1; h<=n; h++)	scanf("%c",&c) , d[1][h] = c-48 , par2[h] = d[1][h] + par2[h-1];
	
	vis[0][1] = vis[1][0] = dp[0][1] = dp[1][0] = 1;
	
	//printf("%d\n",tap(1,2));
	
	if(tap(n,n) == 0)	printf("Impossible");
	
	else
	{
		int a=0,k[2009];
		
		int x = n , y = n;
		
		while(x+y)
		{
			if(x  &&  dp[x-1][y])	x-- , k[a++] = 1;
			else 	y-- , k[a++] = 2;
		}
		
		for(int h=a-1; h>-1; h--)	printf("%d",k[h]);
	}
	
	/*for(int h=0; h<=n; h++)
	{
		for(int j=0; j<=n; j++)	printf("%d %d ____ %d\n",h,j,dp[h][j]);
		printf("\n");
	}*/
}
