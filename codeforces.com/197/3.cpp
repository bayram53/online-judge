# include <stdio.h>
# include <string.h>

int n;

int san[19] , dp[1009][19][19] , D[1009],d;

char c;

int main()
{
	memset(dp , -1 , sizeof(dp));
	
	for(int h=1; h<11; h++)	{scanf("%c",&c); if(c == '1')	san[h] = 1 , dp[1][h][h] = h;}
	
	scanf("%d",&n);
	
	
	for(int h=1; h<n; h++)
		for(int j=1; j<11; j++)
			for(int i=1; i<10; i++)
			if(dp[h][j][i] != -1)
			{
				for(int f=1; f<11; f++)
					if(i < f  &&  j != f  &&  san[f])
						dp[h+1][f][f-i] = j;
			}
	
	for(int j=1; j<11; j++)
		for(int i=1; i<11; i++)
			if(dp[n][j][i] != -1)
			{
				int k = j , l = i , m;
				
				printf("YES\n");
				
				while(l)
				{
					D[d++] = k;
					m = l;
					l = k-l;
					k = dp[n-d+1][k][m];
				}
				
				for(int h=d-1; h>-1; h--)	printf("%d ",D[h]);
				
				return 0;
			}
				
	
	printf("NO");
}
