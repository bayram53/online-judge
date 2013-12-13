# include <stdio.h>

# define MAXN 2009
# define mi(x,y) (x<y ? x : y)

int n, m, all, r, c, mn = MAXN;
char s[MAXN][MAXN];
int dp[MAXN][MAXN];

int sum(int r1,int c1,int r2,int c2)
{
	if(r2 < r1  ||  c2 < c1)	return 0;
	
	return dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
}

int b_s(int x,int y,int l,int r)
{
	if(r-l < 2)
	{
		if(sum(x, y, x+l-1, y+l-1) - sum(x+1, y+1, x+l-2, y+l-2) == all)	return l;
		if(sum(x, y, x+r-1, y+r-1) - sum(x+1, y+1, x+r-2, y+r-2) == all)	return r;
		return MAXN;
	}
	
	int mid = (l+r)/2;
	if(sum(x, y, x+mid-1, y+mid-1) - sum(x+1, y+1, x+mid-2, y+mid-2) < all)	return b_s(x, y, mid, r);
	return b_s(x, y, l, mid);
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",s[h]);
		
		for(int j=0; j<m; j++)	dp[h+1][j+1] = (s[h][j] == 'w' ? 1 : 0), all += (s[h][j] == 'w' ? 1 : 0);
		for(int j=1; j<=m; j++)	dp[h+1][j] += dp[h+1][j-1];
	}
	
	for(int h=1; h<=n; h++)
		for(int j=1; j<=m; j++)
			dp[h][j] += dp[h-1][j];
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			int tmp = b_s(i, j, 1, mi(m-j, n-i)+1);
			
			if(tmp < mn)	r = i, c = j, mn = tmp;
		}
	
	if(mn == MAXN)	{printf("-1"); return 0;}
	
	///printf("%d %d : %d\n",r,c,mn);
	
	r--, c--;
	
	for(int h=0; h<mn; h++)
	{
		if(s[r+h][c] == '.')	s[r+h][c] = '+';
		if(s[r][c+h] == '.')	s[r][c+h] = '+';
		if(s[r+mn-1][c+h] == '.')	s[r+mn-1][c+h] = '+';
		if(s[r+h][c+mn-1] == '.')	s[r+h][c+mn-1] = '+';
		
	}
	
	for(int h=0; h<n; h++)	printf("%s\n",s[h]);
	
}
