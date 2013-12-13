# include <stdio.h>

# define san 10000000000

int n,k;
long long a;
int t[2009];

int main()
{
	scanf("%d %d",&n,&k);
	
	k %= n;
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]),t[h+n]=t[h];
	
	for(int h=0; h<10; h++)
		a *= 10 , a += t[h];
	
	for(int h=10; h<k+11; h++)
		a %= san , a *=10 , a += t[h];
	
	printf("%lld",a/10);
}
