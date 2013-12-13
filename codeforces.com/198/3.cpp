# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <vector>

using namespace std;

long long gcd(long long n,long long m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}


long long n,ans;

long long D[100009],F[100009];

int main()
{
	cin>>n;
	
	for(int h=0; h<n; h++)	cin>>D[h];
	
	sort(D,D+n);
	
	for(int h=n-1; h>0; h--)	F[n-h] = F[n-h-1] + D[h]-D[0];
	
	for(int h=1; h<n; h++)	ans += F[h]-((long long)h*(D[n-h]-D[0]));
	
	ans += F[n-1];
	
	ans *= 2;
	
	for(int h=0; h<n; h++)	ans += D[h];
	
	long long k = gcd(ans,n);
	
	ans /= k;
	n /= k;
	
	cout<<ans<<' '<<n;
}
