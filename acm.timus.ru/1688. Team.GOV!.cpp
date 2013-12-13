# include <stdio.h>

long long  n , k ,a;

int main()
{
	scanf("%lld %lld",&n,&k);
	
	n *= 3;
	
	for(int h=1; h<=k; h++)
	{
		scanf("%lld",&a);
		
		if(0 > n - a)
			{ printf("Free after %d times.",h); return 0;}
		n -= a;
	}
	
	printf("Team.GOV!");
}
