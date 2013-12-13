# include <stdio.h>

long long n,a;
double sum;

int main()
{
	scanf("%lld",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%lld",&a);
		sum+=(a*1.0);
	}
	
	printf("%.6lf",sum/(n*1.0));
}
