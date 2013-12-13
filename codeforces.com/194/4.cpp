# include <stdio.h>
# include <math.h>

long long k=1;

int main()
{
	for(long long h=1; h<37; h++)
		k *= 3 , printf("%lld %lld\n",k,(long long)pow(3.0,h*1.0));
	
}
