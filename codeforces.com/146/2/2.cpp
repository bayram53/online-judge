# include <iostream>
# include <algorithm>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define mod 1073741824

using namespace std;

int a,b,c;
int t[1000009];
long long ans=0;

int main()
{
	cin>>a>>b>>c;
	
	for(int h=2; h<=1000000; h++)
	{
		for(int j=h; j<=1000000; j+=h)
		t[j]++;
	}
	
	for(int h=1; h<=a; h++)
	for(int j=1; j<=b; j++)
	for(int i=1; i<=c; i++)
	{
		ans+=t[h*i*j]+1;
		ans%=mod;
	}
	
	cout<<ans;
}
