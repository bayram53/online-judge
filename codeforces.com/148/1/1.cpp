# include <iostream>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

long long y,k,n;
long long v=0;
long long x;

int main()
{
	cin>>y>>k>>n;
	
	x=(y/k+1)*k;
	
	while(x<=n)
	{
		cout<<x-y<<" ";
		x+=k;
		v=1;
	}
	
	if(v==0)
	cout<<-1;
	
}
