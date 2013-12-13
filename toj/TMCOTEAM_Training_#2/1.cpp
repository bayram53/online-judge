# include <stdio.h>
# include <string.h>

# define ma(x,y) (x>y ? x : y)

int dp[1009][1009], t, n;

int main(){
	
	for(int i=0; i<1001; i++)
		for(int j=0; j<1001; j++)
			dp[i][j] = 1;
	
	for(int i=2; i<1001; i++)
		dp[0][i] = dp[i][0] = 0;
	
	dp[0][0] = 0;
	
	for(int i=1; i<1001; i++)
		for(int j=1; j<1001; j++)
			if(dp[i][j])
				for(int h=2; ma(h*i, h*j)<1001; h++)	dp[h*i][h*j] = 0;
	
	for(int i=1; i<1001; i++)
		for(int j=0; j<1001; j++)
			dp[i][j] += dp[i-1][j];
	
	for(int i=0; i<1001; i++)
		for(int j=1; j<1001; j++)
			dp[i][j] += dp[i][j-1];
	
	scanf("%d",&t);
	
	for(int i=1; i<=t; i++)
	{
		scanf("%d",&n);
		
		printf("%d %d %d\n",i,n,dp[n][n]);
	}
}
