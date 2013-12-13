# include <iostream>
# include <stdio.h>
# include <algorithm>

using namespace std;

long long n,k;
long long ans;

long long mal(long long x)
{
	return x*(x+1)/2 - (x-100000)*(x-100001)/2;
}

int main()
{
	cin>>n>>k;
	
	/*if(n == k)
	{
		printf("1");
		return 0;
	}*/
	
	if(n-1 > k*(k-1)/2)
	{
		printf("-1");
		return 0;
	}
	
	k--;
	n--;
	
	while(n)
	{
		if(k >= 100000  &&  n>=mal(k))
			n -= mal(k) , ans+=100000 , k -= 100000;
		
		if(k <= n)
			ans++ , n -= k, k--;
		else
			ans++ , n = 0;
	}
	
	cout<<ans;
}
