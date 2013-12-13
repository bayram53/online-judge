# include <stdio.h>

double a,b,c;
double x1,x2,x3;

int main()
{
	scanf("%lf %lf %lf",&a,&b,&c);
	
	x1 = 1.0;
	x2 = a/b;
	x3 = a/c;
	
	double san = x1+x2+x3;
	
	san = 1000.0 / san;
	
	printf("%d",(int) (san * a + 0.5));
}
