# include <stdio.h>

long long r(long long x)
{
	if(x<10)
		return x;
	return 10;
}

long long n,ans;
long long t[109][19];

long long tap(long long x,long long y)
{
	if(t[x][y]!=0)
		return t[x][y];
	
	if(float(x/9)>float(y))
		return 0;
	int s=r(x);
	for(int h=0; h<s; h++)
		t[x][y]+=tap(x-h,y-1);
		
	return t[x][y];
}

int main()
{
	scanf("%lld",&n);
	
	for(int h=1; h<10; h++)	
		t[h][1]=1;
	
	long long k=tap(n,10);
	
	if(n==1)
		ans=1;
	
	for(int h=1; h<10; h++)
		ans+=t[n][h];
		
	printf("%lld",ans);
}
