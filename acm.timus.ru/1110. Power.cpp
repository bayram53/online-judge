# include <stdio.h>

long bigmod(long b,long p,long m) {
  if (p == 0)
    return 1;
  else if (p%2 == 0)
    {
		long long g=bigmod(b,p/2,m);
		
		return (g*g) % m;
	}
  else
    return ((b % m) * bigmod(b,p-1,m)) % m;
}

long long a,b,c,d=0;

int main()
{
	scanf("%lld %lld %lld",&a,&b,&c);
	
	for(int h=0; h<b; h++)
	{
		if(bigmod(h,a,b)==c)
		{
			printf("%d ",h);
			d++;
		}
	}
	
	if(d==0)
		printf("-1");
}
