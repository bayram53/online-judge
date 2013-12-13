# include <stdio.h>

double a,b;

int main()
{
	scanf("%lf %lf",&a,&b);
	
	for(long long h=1; h<10000000; h++)
	{
		double k = (double)h ;
		
		double x = k*a/100.0;
		double y = (k-(1e-7))*b/100.0;
		int s = (long long)y;
		
		if(s * 1.0 > x  &&  s * 1.0 < y)
			{printf("%lld",h); return 0;}
	}
}
