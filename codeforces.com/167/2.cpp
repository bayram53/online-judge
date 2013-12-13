# include <algorithm>
# include <stdio.h>
# include <string.h>
# include <iostream>
# include <stdlib.h>

using namespace std;

long long n ,  a;
long long ans;
long long t[100009];
long long d[100009];

int tap(long long x)
{
	if(x == 0)
		return 0;
	if(x == 1)
		return 1;
	
	if(x % 2 == 0)
		return tap(x/2);
	return tap(x/2) +1;
}

int main()
{
	cin>>n;
	
	for(int h=0; h<n; h++)
		cin>>a , d[tap(a)]++;
	
	for(int h=0; h<100001; h++)
		ans += (d[h] * (d[h]-1))/2;
	
	cout<<ans;
}
