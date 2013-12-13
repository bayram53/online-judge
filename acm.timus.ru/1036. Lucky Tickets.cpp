# include <stdio.h>

# define ma(x,y) (x>y ? x : y)

int n,s,r,e;

int dp[59][509][101];

int d[5009];

int main()
{
	scanf("%d %d",&n,&s);
	
	if(s%2)	{printf("0");return 0;}
	
	dp[0][0][0] = 1;
	
	for(int h=1; h<=n; h++)
		for(int j=0; j<=s/2; j++)
			for(int i=0; i<10; i++)
					if(j >= i)
					{
						r = 0;
						
						for(int p=0; p<99; p++)	dp[h][j][p] += dp[h-1][j-i][p]+r , r = dp[h][j][p]/10 , dp[h][j][p] %= 10;
					}
	
	for(int h=99; h>-1; h--)
	{
		e = h;
		
		if(dp[n][s/2][h])	break;
	}
	
	for(int h=0; h<=e; h++)
		for(int j=0; j<=e; j++)
			d[h+j] += dp[n][s/2][h]*dp[n][s/2][j];
	
	r = 0;
	
	for(int h=0; h<99; h++)	d[h] += r , r = d[h]/10 , d[h] %= 10;
	
	for(int h=99; h>-1; h--)
	{
		e = h;
		
		if(d[h])	break;
	}
	
	for(int h=e; h>-1; h--)	printf("%d",d[h]);
}
