# include <iostream>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# define mi(x,y) (x<y ? x : y)

long long n,x,y,c;

using namespace std;

long long ku(long long x)
{
	if(x<0)
		return 0;
	return x*x;
}

long long ka(long long x)
{
	if(x<0)
		return 0;
	return x*(x+1)/2;
}

long long bil(long long s)
{
	long long a=s*(s+1)*2;
	
	a-=ku(s-x+1);
	a-=ku(s-y+1);
	a-=ku(s-n+x);
	a-=ku(s-n+y);
	
	a+=ka(s-x+1-y);
	a+=ka(s-y-(n-x));
	a+=ka(s-x-(n-y));
	a+=ka(s-(n-x)-(n-y)-1);
	
	return a;
}

long long tap(long long x,long long y)
{
	if(abs(y-x)==1)
	{
		if(bil(x)>=c)
			return x;
		
		else
			return y;
	}
	
	if(bil((x+y)/2)<c)
		return tap((x+y)/2,y);
		
	return tap(x,(x+y)/2);
}

int main()
{
	cin>>n>>x>>y>>c;
	
	c-=1;
	
	if(c==0)
		{cout<<'0';return 0;}
	
	cout<<tap(1,2000000000);
}	
