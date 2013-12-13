# include <stdio.h>

int n,m;

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int main()
{
	scanf("%d %d",&n,&m); n--,m--;
	printf("%d",n + m - gcd(n , m));
}
