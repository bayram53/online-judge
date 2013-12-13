# include <stdio.h>
# include <string.h>
# include <ctype.h>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

int n,m,k,a=-1;

char s[100009],c;

int d[100009];

int dp[100009];

int main()
{
	scanf("%d %d%c",&n,&m,&c);
	
	while(1)
	{
		scanf("%c",&c);
		
		if(c == '\n')	break;
		
		s[k++] = c;
	}
	
	for(int h=0; h<k; h++)
	{
		if(s[h] != ' '  &&  !isalpha(s[h]))	a = h;
		
		d[h+1] = a+1;
	}
	
	for(int h=1; h<=k; h++)
	{
		if(h-d[h] > n)  dp[h] = dp[ma(h-m,d[h])]+1;
		else dp[h] = dp[ma(0,h-n)]+1;
	}
	
	//for(int h=1; h<=k; h++)	printf("%d _ %d\n",h,dp[h]);
	
	printf("%d",dp[k]);
}
