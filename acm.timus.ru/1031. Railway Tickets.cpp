# include <stdio.h>
# include <limits.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

int l1,l2,l3,c1,c2,c3;

int d[10009];

int n,a,b;

int dp[10009];

int cost(int x)
{
	if(x <= l1)	return c1;
	if(x <= l2)	return c2;
	return c3;
}

int main()
{
	scanf("%d %d %d %d %d %d",&l1,&l2,&l3,&c1,&c2,&c3);
	
	scanf("%d %d %d",&n,&a,&b);
	
	d[1] = 1;
	
	for(int h=0; h<=n; h++)	dp[h] = INF;
	
	for(int h=2; h<=n; h++)	scanf("%d",&d[h]) , d[h]++;
	
	if(b < a)	swap(a,b);
	
	dp[a] = 0;
	
	for(int h=a; h<b; h++)
		for(int j=h+1; j<=b; j++)
		{
			if(d[j]-d[h] > l3)	break;
			
			if(d[h]-d[j] == 0)	dp[j] = mi(dp[h],dp[j]);
			
			dp[j] = mi(dp[h]+cost(d[j]-d[h]),dp[j]);
		}
	
	printf("%d",dp[b]);
}
