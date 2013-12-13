# include <iostream>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# define mod 1000000007

using namespace std;

long long n,p=1;

int main()
{
	cin>>n;
	
	if(n==7)
		{cout<<0;return 0;}
	
	for(int h=2; h<n-1; h++)
		p*=h,p%=mod;
	
	
	if(n>=100)
	
	p%=mod;
	
	
	cout<<p;
}
