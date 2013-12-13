# include <stdio.h>

# define MAXN 2009

int n, t, f, d;

double top = 0.0, ans = 20009.0;

double vak(double x)
{
	if(x < 0.0)	return x*(-1.0);
	return x;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<2*n; h++)
	{
		double a;
		
		scanf("%lf",&a);
		
		int f1 = a;
		
		d += f1;
		
		if(a == (double)f1)	t++;
		
		else 	f++;
		
		top += a;
	}
	
	int tmp = t;
	
	if(n < t)	tmp = n;
	
	for(int h=0; h<=tmp; h++)
	{
		double mal = (double)d;
		double s = (double)(n-h);
		mal += s;
		if(vak(mal-top) < ans)	ans = vak(mal-top);
	}
	
	printf("%.3lf",ans);
}
