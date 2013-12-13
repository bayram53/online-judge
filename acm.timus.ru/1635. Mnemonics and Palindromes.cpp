# include <stdio.h>
# define inf 999999
# include <string.h>
# include <stdlib.h>

int n,m;
char c[6009];
int dp[6009][6009];
int ans[6009][10];
char a[6009][6009];

int main()
{
	for(int h=0; h<4008; h++)
		ans[h][0]=inf;
	
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=0; h<n; h++)
	{
		dp[h][h+1]=1;
		int s=h-1,d=h+1;
		
		while(s>-1 && d<n)
		{
			if(c[s]!=c[d])
				break;
			dp[s][d+1]=1;
			s--;
			d++;
		}
		
		s=h;
		d=h+1;
		ans[0][0]=0;
		while(s>-1 && d<n)
		{
			if(c[s]!=c[d])
				break;
			dp[s][d+1]=1;
			s--;
			d++;
		}
	}
	
	for(int h=0; h<n; h++)
		for(int j=1; j<=n; j++)
			if(ans[j][0]>ans[h][0]+1 && dp[h][j]==1)
				ans[j][0]=ans[h][0]+1,ans[j][1]=h;	
	
	printf("%d\n",ans[n][0]);

	int r1=ans[n][1],r2=n,l=0;
	
	while(r2!=0)
	{
		for(int h=r1; h<r2; h++)
			a[l][h-r1]=c[h];
		
		int o=r1;
		r2=r1;
		r1=ans[o][1];
		l++;
	}
	
	for(int h=ans[n][0]-1; h>-1; h--)
		printf("%s ",a[h]);
		
}
