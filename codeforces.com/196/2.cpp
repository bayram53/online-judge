# include <stdio.h>

int a,b,c,d,x,y;

long long x1,y1;

int gcd(int x,int y)
{
	if(y == 0)	return x;
	return	gcd(y,x%y);
}

long long gcd(long long x,long long y)
{
	if(y == 0)	return x;
	return	gcd(y,x%y);
}


int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	int k = gcd(a,b);
	a /= k;
	b /= k;
	k = gcd(c,d);
	c /= k;
	d /= k;
	
	a = a*c*d;
	b = b*c*d;
	
	int h = 0;
	
	while(1)
	{
		h++;
		
		if(h*c > a  ||  h*d > b)	break;
		
		y1 = (long long)a*(long long)b;
		x1 = (long long)(h*c)*(long long)(h*d);
		
		long long r = gcd(x1,y1);
		
		x1 /= r;
		y1 /= r;
	}
	
	printf("%I64d/%I64d",y1-x1,y1);
}
