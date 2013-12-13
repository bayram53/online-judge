# include <stdio.h>

int dp[1009][1009][3],last=1008;

int a,b;

int main()
{
	for(int h=1; h<1001; h++) 	dp[1][h-1][0] = h , dp[1][h-1][1] = h;
	dp[1][last][0] = 1000;
	
	for(int h=1; h<1000; h++)
	{
		int k = 1;
		int &d = dp[h+1][last][0];
		
		dp[h+1][d][1] = dp[h+1][d][0] = 1;	d++;
		
		for(int j=0; j<dp[h][last][0]; j++)
		{
			k += dp[h][j][0]+1;
			
			dp[h+1][d][0] = k;
			dp[h+1][d++][1] = dp[h][j][1]+1;
			
			if(k >= 1000)	break;
		}
	}
	
	//for(int h=0; h<dp[5][last][0]; h++)	printf("%d %d\n",dp[5][h][0],dp[5][h][1]);
	
	scanf("%d %d",&a,&b);
	
	while(a)
	{
		for(int h=0; h<dp[a][last][0]; h++)
			if(dp[a][h][0] >= b)	{printf("%d\n",dp[a][h][1]); break;}
		
		scanf("%d %d",&a,&b);
	}
}
