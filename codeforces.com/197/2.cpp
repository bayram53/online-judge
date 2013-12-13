# include <stdio.h>
# include <iostream>

using namespace std;

long long m,a,b,ans,n;

int main()
{
	
	cin>>n>>m>>a;
	ans = a-1;
	
	for(int h=0; h<m-1; h++)
	{
		cin>>b;
		
		if(b < a)	ans += (b+n)-a;
		else ans += b-a;	
		
		a = b;
	}
	
	cout<<ans;
}
