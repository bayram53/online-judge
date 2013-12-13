# include <stdio.h>

int n,m;
int t[1009];
int cost[509][509];
int dp[509][2];

int mi(int x,int y)
{
	if(x==-1)
		return y;
	if(y==-1)
		return x;
		
	return (x<y ? x : y);
}

int tap(int x,int z)
{
	if(cost[x][z]!=-1)
		return cost[x][z];
	
	if(z==1)
		return (dp[n][0]-dp[x][0])*(dp[n][1]-dp[x][1]);
	
	for(int h=x; h<n-z+1; h++)
		cost[x][z]=mi(cost[x][z],(dp[h+1][0]-dp[x][0])*(dp[h+1][1]-dp[x][1])+tap(h+1,z-1));
	
	return cost[x][z];
}

int main()
{
	for(int h=0; h<509; h++)
		for(int j=0; j<509; j++)
			cost[h][j]=-1;
	
	scanf("%d %d",&n,&m);
	
	for(int h=1; h<=n; h++)
	{
		scanf("%d",&t[h-1]);
			dp[h][0]=dp[h-1][0],dp[h][1]=dp[h-1][1],dp[h][t[h-1]]++;
	}
	
	printf("%d",tap(0,m));
}

