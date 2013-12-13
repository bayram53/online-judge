# include <iostream>
# include <stdio.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)

using namespace std;

long long a,b,m,ans;

int main()
{
	cin>>a>>b>>m;
	
	if(a >= m  ||  b >= m)	{cout<<0;return 0;}
	
	if(a < 1  &&  b < 1)
	{
		if(a >= m  ||  b >= m)	cout<<0;
		else 	cout<<-1;
	}
	
	else
	{
		if(mi(a,b) < 0)
		{
			if(b < a)	swap(a,b);
			long long k = (-1*a)+b,p;
			p = k/b;
			ans = p;
			a += b*p;
		}
		
		while(max(a,b) < m)
		{
			if(a < b) a += b;
			else b += a; 
			ans++;
		}
		
		cout<<ans;
	}
}
