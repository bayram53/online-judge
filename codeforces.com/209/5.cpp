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
	scanf("%d %d",&n,&m);
	
	printf("%d",gcd(n,m));
	
getchar();
getchar();	
}
