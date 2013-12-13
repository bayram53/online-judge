# include <stdio.h>

long long n,k;
long long t[29];
long long a,b;

int main()
{
	b = 1;
	
	scanf("%lld %lld",&n,&k);
	
	for(long long h=n-1; h>-1; h--)
		scanf("%lld",&t[h]);
	
	t[n++] = k;
	
	for(long long h=n-1; h>0; h--)
		printf("%lld ",t[h]/t[h-1]-1);
}
