# include <stdio.h>
# include <math.h>

int n;
double k,a,b,ans;
double c,d,x,y;

double yol(double x1,double y1,double x2,double y2)
{
	return sqrt((x2 - x1) * (x2 - x1)  +  (y2 - y1) * (y2 - y1));
}

int main()
{
	scanf("%d %lf",&n,&k);
	
	scanf("%lf %lf",&a,&b);
	
	c = a;
	d = b;
	
	for(int h=1; h<n; h++)
	{
		scanf("%lf %lf",&x,&y);
		ans+=yol(a,b,x,y);
		a = x;
		b = y;
	}
	
	ans += yol(a,b,c,d);
	
	ans += 3.14159*2*k;
	
	printf("%.2lf",ans);
}
