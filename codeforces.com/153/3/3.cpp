# include <iostream>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

int n,d;
long long ans=0;
long long g[100009];
int t[100009];

int main()
{
	cin>>n>>d;
	for(int h=0; h<n; h++)
		cin>>t[h],g[h]=t[h];
	g[0]=0;

	for(int h=1; h<n; h++)
		g[h]=g[h-1]+abs(t[h]-t[h-1]);
		int a=0,k=0;
		
	while(k<n)
	{
		for(int h=a; h<n; h++)
		{
			if(g[h]-g[k]>d)
			{
				a=h-1;
				break;
			}
			a=h;
		}
		
		if(a-k-1>0)
		ans+=((a-k)*(a-k-1));
		k++;
	}
	
	cout<<ans/2;
}
