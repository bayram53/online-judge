# include <stdio.h>
# include <string.h>

long long bigmod(long long b,long long p,long long m) {
	if (p == 0)
		return 1;
    
  else if (p%2 == 0)
	{
		long long k=bigmod(b,p/2,m);
		return k * k % m; 
	}
	
	else
		return ((b % m) * bigmod(b,p-1,m)) % m;
}

char s[100];
int m,ans=0;

int main()
{
	scanf("%s",s);
	
	m=strlen(s);
	
	ans+=(s[m-1]-48)%7;
	
	for(int h=m-2; h>-1; h--)
	ans+=((s[h]-48)*bigmod(10,m-h-1,7))%7;
	
	printf("%d",ans%7);
}
