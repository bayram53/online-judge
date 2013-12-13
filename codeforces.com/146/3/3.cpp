# include <iostream>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

long long n,ans,ma=-1;

long long gcd(long long n,long long m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

long long lcm(long long a,long long b)
{
return a/gcd(a,b)*b;
}

int main()
{
	cin>>n;
	
	ans=n*(n-1);
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	if(n==2)
	{
		cout<<2;
		return 0;
	}
	
	if(n==3)
	{
		cout<<6;
		return 0;
	}
	
	for(int h=2; h<n-1; h++)
	if(
	lcm(ans,h)>ma)
		ma=lcm(ans,h);
		
	
	if(n%2==0)
	{
		if((n-1)*(n-2)*(n-3)>ma)
			cout<<(n-1)*(n-2)*(n-3);
		
		else
			cout<<ma;
		
	}
	
	else
	cout<<ma;
}
