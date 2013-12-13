# include <stdio.h>

long long n,m;
long long san=1,ans=0;

int main()
{
	scanf("%lld %lld",&n,&m);
	
	while(san<m && n-san>0)
	{
		san+=san;
		ans++;
	}
	
	if(n-san<=0)
	{
		printf("%lld",ans);
		return 0;
	}
	
	if((n-san)%m!=0)
	ans++;
	
	printf("%lld",ans+(n-san)/m);
}
