# include <stdio.h>

# define MAXN 100009
# define ma(x,y) (x>y ? x : y)

int n, ans, k;

int a[MAXN], b[MAXN], dp[MAXN];

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&a[h]);
	
	for(int h=1; h<=n; h++)	dp[h] = dp[h-1]+a[h];
	
	for(int h=1; h<=n; h++)	scanf("%1d",&b[h]), ans += b[h]*a[h];
	
	for(int h=n; h>0; h--)
	{
		if(b[h])	ans = ma(ans, k+dp[h-1]);
		
		k += a[h]*b[h];
	}
	
	printf("%d",ans);
}
