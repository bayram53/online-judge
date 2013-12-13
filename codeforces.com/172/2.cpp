# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <vector>
# include <limits.h>
# include <stdlib.h>

using namespace std;

typedef long long llint;

llint gcd(llint n,llint m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

llint lcm(llint a,llint b)
{
return a/gcd(a,b)*b;
}

llint a,b,n;
llint x,y;
long double z;

int main()
{
	cin>>a>>b>>n;
	
	for(llint h=1; h<=n; h++)
	{
		llint k = lcm(h,b);
		llint l = k/b*a;
		llint s = k/h;
		llint e = l/s;
		
		long double r = (long double)(e*s-l);
		long double d = r/(long double)k;
		
		if(d < 0.0)
			d *= -1.0;
		
		if(x == 0  ||  d < z)
		{	
			z = d;
			x = h;
			y = e;
		}
		
		
		e++;
		r = (long double)(e*s-l);
		d = r/(long double)k;
		
		if(d < 0.0)
			d *= -1.0;
		
		if(x == 0  ||  d < z)
		{
			z = d;
			x = h;
			y = e;
		}
	}
	
	/*llint thegcd = gcd(x,y);
	
	if(thegcd) x/=thegcd , y/=thegcd;*/
	
	cout<<y<<'/'<<x;
}
//38133 49787 9840
