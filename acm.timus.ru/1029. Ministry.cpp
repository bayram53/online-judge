# include <stdio.h>
# include <string.h>

typedef long long llint;

int n,m;

llint d[109][509];

llint dp[109][509][4];

int ans[50009][3],a;

int main()
{
	memset(dp , -1 , sizeof(dp));
	
	scanf("%d %d",&m,&n);
	
	for(int h=0; h<m; h++)
		for(int j=0; j<n; j++)
			scanf("%lld",&d[h][j]);
	
	for(int h=0; h<n; h++)	dp[0][h][0] = d[0][h];
	
	for(int h=1; h<m; h++)
		for(int j=0; j<n; j++)
		{
			llint k = dp[h-1][j][0] + d[h][j];
			
			if(dp[h][j][0] == -1  ||  dp[h][j][0] > k)	dp[h][j][0] = k , dp[h][j][1] = h-1 , dp[h][j][2] = j;
			
			for(int i=j+1; i<n; i++)
			{
				k += d[h][i];
				
				if(dp[h][i][0] == -1  ||  dp[h][i][0] > k)	dp[h][i][0] = k , dp[h][i][1] = h ,  dp[h][i][2] = i-1;
			}
			
			k = dp[h-1][j][0] + d[h][j];
			
			for(int i=j-1; i>-1; i--)
			{
				k += d[h][i];
				
				if(dp[h][i][0] == -1  ||  dp[h][i][0] > k)	dp[h][i][0] = k , dp[h][i][1] = h , dp[h][i][2] = i+1;
			}
		}
	
	int p = 0;
	
	for(int h=1; h<n; h++) if(dp[m-1][p][0] > dp[m-1][h][0])	p = h;
	
	ans[a][0] = m-1;
	ans[a][1] = p;
	
	while(ans[a][0])
	{
		int x = ans[a][0] , y = ans[a][1];
		
		a++;
		
		ans[a][0] = dp[x][y][1];
		ans[a][1] = dp[x][y][2];
	}
	
	for(int h=a; h>-1; h--)	printf("%d ",ans[h][1]+1);
}
