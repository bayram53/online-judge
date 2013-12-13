# include <stdio.h>
# define mi(x,y) (x<y ? x : y)

int n,m,x,y,a,b;

int gcd(int x,int y)
{
	if(y == )	return x;
	return gcd(y,x%y);
}

int main()
{
	scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&a,&b);
	
	int k = gcd(a,b),l;
	a /= k;
	b /= k;
	
	int p = ma(n/a,m/b);
	
	a *= p;
	b *= p;
	
	
}
