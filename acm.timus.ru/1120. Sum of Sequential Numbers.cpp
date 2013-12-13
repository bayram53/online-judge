# include <stdio.h>
# include <algorithm>

using namespace std;

long long n;

long long top(long long x,long long y)
{
	return (x+y)*(x+y-1)/2-(x-1)*x/2;
}

long long bs(long long l,long long r ,long long x,long long y)
{
	if(abs(r-l)<2)
	{
		if(top(l,x)==y)
			return l;
		
		else if(top(r,x)==y)
			return r;
		
		return 0;
	}
	
	if(top((l+r)/2,x)<y)
		return bs((l+r)/2+1,r,x,y);
		
	return bs(l,(l+r)/2,x,y);
	
}

int main()
{
	scanf("%lld",&n);
	
	for(long long h=31624; h>0; h--)
	if(bs(1,1000000000,h,n)!=0)
	{
		printf("%lld %lld",bs(1,1000000000,h,n),h);
		return 0;
	}
}
