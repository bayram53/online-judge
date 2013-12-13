# include <stdio.h>

long long n,m;
long long ans;

int main()
{
	scanf("%lld %lld",&n,&m);
	
	n--;
	
	if(n<m)
		printf("%lld",n*2);
	
	else if(n==m)
		printf("%lld",n*2-1);
		
	else
		printf("%lld",m*2-1);
}
