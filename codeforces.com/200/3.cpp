# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <limits.h>

# define mi(x,y) (x<y ? x : y)

using namespace std;

typedef long long llint;

llint a, b, c, ans, k = LLONG_MAX;

llint gcd(llint n,llint m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int main()
{
	cin>>a>>b;
	
	c = gcd(a, b);
	
	a /= c; 
	b /= c; 
	
	ans += a/b;
	
	if(a%b)
	{
		a = a%b;
		
		if(a == 1)
		{
			cout<<b+ans;
			return 0;
		}
		
		ans += a/(b-a)+1;
	}
	
	cout<<ans;
}
