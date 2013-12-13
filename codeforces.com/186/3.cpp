# include <iostream>
# include <math.h>
# include <algorithm>
# define ma(x,y) (x>y ? x : y)

typedef long long llint;

using namespace std;

llint n,k,a=4,b=1,ans;

llint d[2000009];

int main()
{
	cin>>n;
	
	k = (llint)log2(sqrt(n*1.0));
	//cout<<k;
	for(llint h=0; h<n; h++)	cin>>d[h];
	
	sort(d , d+n);
	
	ans += d[n-1]*(k+1);
	
	for(int h=n-2; h>-1; h--)
	{
		for(int j=0; j<a-b; j++) ans += d[h--]*k;
		h++;
		k--;
		a *= 4;
		b *= 4;
	}
	
	cout<<ans;
}
