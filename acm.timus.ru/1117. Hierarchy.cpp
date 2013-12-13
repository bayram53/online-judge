# include <stdio.h>
# include <algorithm>

using namespace std;

long long n,m;
long long a;
long long t[40];
long long k[40];

long long lo(long long x)
{
	for(int h=1; h<36; h++)
		if(k[h-1]<=x && k[h]>x)
			return h-1;
}

long long tap(long long x,long long y)
{
	if(x==1 || x==3 || x==2)
		return 0;
	
	if(y==x)
		return t[lo(y)]+lo(y)-1;
	
	if(x>y)
		return t[lo(x)]+2*(lo(x)-1)+tap(x-y,y/2);
	
	return tap(x,y/2);
}

int main()
{
	k[0]=1;
	
	for(int h=1; h<40; h++)
		k[h]=k[h-1]*2;
	
	a=k[30];
	
	scanf("%lld %lld",&n,&m);
	
	if(n>m)
		swap(n,m);
	
	t[2]=0;
	
	for(int h=3; h<40; h++)
		t[h]=2*(t[h-1]+h-2);
	
	printf("%lld",tap(m,a)-tap(n,a));
}
