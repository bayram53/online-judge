# include <iostream>
# include <vector>
# include <algorithm>
# include <string.h>
# include <string>
# include <stdlib.h>

using namespace std;

long long n,m,ans=1;
char t[109][109];
bool d[109][300];

int main()
{
	cin>>n>>m;
	
	for(int h=0; h<n; h++)
	cin>>t[h];
	
	for(int h=0; h<m; h++)
	{
		long long g=0;
		for(int j=0; j<n; j++)
		if(d[h][int(t[j][h])]!=1)
		{
			g++;
			d[h][int(t[j][h])]=1;
		}
		
		ans*=g;
		ans%=1000000007;
	}
	
	cout<<ans;
}
