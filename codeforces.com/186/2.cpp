# include <stdio.h>
# include <string.h>

int n,a,b;

char s[1000009];

int dp[1000009];

int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	
	int m = strlen(s);
	
	for(int h=1; h<=m; h++)
	{
		dp[h] += dp[h-1];
		
		if(h != 1  &&  s[h-1] == s[h-2])	dp[h]++;
	}
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[b]-dp[a]);
	}
}
