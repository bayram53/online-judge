# include <stdio.h>
# include <string.h>

double D[209], st[209][209], dp[209][209];
int n, m, t;

double in(int x, int y, int z)
{
	double a = (double)(z-x), b = (double)(y-x);
	return D[x] + (D[y]-D[x])*a/b;
}

double yep(double x)
{
	if(x < 0.0)	return x*-1.0;
	return x;
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n,&m);
		
		for(int h=0; h<n; h++)	scanf("%lf",&D[h]);
		
		for(int h=0; h<n; h++)
			for(int j=h+1; j<n; j++)
			{
				st[h][j] = 0.0;
				
				for(int i=h+1; i<j; i++)	st[h][j] += yep(in(h, j, i)-D[i]);
			}
		
		for(int h=0; h<n; h++)
			for(int j=1; j<=n; j++)
				dp[h][j] = -1.0;
		
		dp[0][1] = 0.0;
		
		for(int h=0; h<n-1; h++)
			for(int j=1; j<n; j++)
				if(dp[h][j] != -1)
					for(int i=h+1; i<n; i++)
						if(dp[i][j+1] == -1  ||  dp[i][j+1] > dp[h][j]+st[h][i])	dp[i][j+1] = dp[h][j] + st[h][i];
		
		/*for(int h=0; h<n; h++)
		{
			for(int j=1; j<=n; j++)	printf("%lf   ",dp[h][j]);
			printf("\n");
		}*/
		
		printf("%.4lf\n",dp[n-1][m]/(double)n);
	}
}
