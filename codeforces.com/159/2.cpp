# include <iostream>
# include <string.h>
# include <algorithm>
# include <limits.h>
# include <vector>
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n,m;
vector <bool> a;

int main()
{
	cin>>n>>m;
	
	cout<<n+m-1-mi(n,m)<<' '<<mi(n,m);
	
}
