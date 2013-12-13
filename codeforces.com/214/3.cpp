# include <stdio.h>

# define MAXB 100005
# define ma(x,y) (x>y ? x : y)

int n, k;
int A[109], B[109], dp[109][2*MAXB+10];

int main()
{
	
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)	scanf("%d",&A[h]);
	for(int h=0; h<n; h++)	scanf("%d",&B[h]) ,B[h] = B[h]*k;
				
	dp[0][A[0] - B[0] + MAXB] = A[0];
	
	for(int h=0; h<n-1; h++)
	{
		for(int j=0; j<MAXB*2; j++)
		{
			if(dp[h][j])
			 dp[h+1][j+A[h+1]-B[h+1]] = ma(dp[h+1][j+A[h+1]-B[h+1]], dp[h][j] + A[h+1]);
			dp[h+1][j] = ma(dp[h+1][j], dp[h][j]);
		}
		
		dp[h+1][A[h+1]-B[h+1]+MAXB] = ma(dp[h+1][A[h+1]-B[h+1]+MAXB], A[h+1]);
	}
	
	printf("%d",(dp[n-1][MAXB] == 0 ? -1 : dp[n-1][MAXB]));
}
