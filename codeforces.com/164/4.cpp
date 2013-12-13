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

int main()
{
	cin>>n;
	
	for(int h=1; h<=n-1; h++)
		m+=h*(n-h);
	cout<<m;
	
}
