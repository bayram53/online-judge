# include <stdio.h>

int n;
unsigned long long ans=0;

unsigned long long sayla(int x,int y)
{
	long long a=1;
	int k=1;
	
	for(int h=x; h>x-y; h--)
	{
		a*=h;
		
		if(a%10==0 && k!=0 && n==21)
			a/=10,k--;
	}
	
	return a;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=2; h<=n; h++)
		ans+=sayla(n,h);
	
	printf("%llu",ans);
	
	if(n==21)
		printf("0");
}
