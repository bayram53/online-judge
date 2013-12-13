# include <iostream>
# include <math.h>

using namespace std;

long double a,b,c,d;
long double a1,c1;

long double ans,x,y=0.000000001;

int main()
{
	cin>>a>>b>>c>>d;
	
	a1 = b-a;
	c1 = d-c;
	
	a1 /= b;
	c1 /= d;
	
	for(int h=0; h<1000; h++)
	{
		if(h)	x = pow(a1,double(h)) , x *= pow(c1,double(h)) , x *= a/b;
		
		else x = a/b;
		
		if(x < y)	break;
		
		ans += x;
	}
	
	cout<<ans;
}
