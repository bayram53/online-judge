# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <string.h>
# include <limits.h>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

int n,m;
long long ans;

int main()
{
	cin>>n;
	
	m=n;
	
	for(int h=1; h<=n; h++)
			ans+=(n-h)*h;	
			
		ans+=n;
	cout<<ans;
}
