# include <stdio.h>

int a,b;

short int dp[10002][3336],san=10001;

void sub(short int x,short int y)
{
	for(short int h=0; h<dp[x][san]; h++)
	{
		if(dp[x][h] < dp[y][h])	dp[x][h+1]-- , dp[x][h] += 10;
		dp[x][h] -= dp[y][h];
	}
	
	for(short int h=dp[x][san]-1; h>-1; h--)
		if(dp[x][h]  ||  !h)
		{
			dp[x][san] = h+1;
			break;
		}
}

int main()
{
	scanf("%d %d",&a,&b);
	
	dp[0][0] = dp[0][san] = 1;
	
	if(b == 0)	dp[1][san] = dp[1][0] = 1;
	else	dp[1][0] = 2 , dp[1][san] = 1;
	
	for(short int h=2; h<=a; h++)
	{
		int carry=0;
		for(short int j=0; j<dp[h-1][san]; j++)	dp[h][j] = carry+dp[h-1][j]*2 , carry = dp[h][j]/10 , dp[h][j] %= 10;
		
		dp[h][san] = dp[h-1][san];
		
		if(carry)	dp[h][dp[h][san]++] = carry;
		
		//dp[h] += dp[h-1]*2;
		
		if(h == b+1)	sub(h,0);//dp[h] -= dp[0];
		else if(h-b-1 > 0)	sub(h,h-b-2);//dp[h] -= dp[h-b-2];
	}
	
	for(short int h=dp[a][san]-1; h>-1; h--)	printf("%d",dp[a][h]);
}
