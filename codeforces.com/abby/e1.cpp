# include <stdio.h>
# include <iostream>

# define mod 1000000000

using namespace std;

typedef long long llint;

int n,m,a,b,k;

char c;

llint d[109];

llint f[200009];

int main()
{
	f[0] = f[1] = 1;
	
	for(int h=2; h<200001; h++)	f[h] = f[h-1]+f[h-2] , f[h] %= mod;
	
	scanf("%d %d",&n,&m);
	
	for(int h=1; h<=n; h++)	cin>>d[h];
	
	for(int h=0; h<m; h++)
	{
		scanf("%d",&k);
		
		c = '-';
		
		if(k == 1)
		{
			while(c != '\n')
			{
				scanf("%d %d%c",&a,&b,&c);
				d[a] = b;
			}
		}
		
		if(k == 2)
		{
			while(c != '\n')
			{
				scanf("%d %d%c",&a,&b,&c);
				
				llint ans = 0;
				
				for(int h=a; h<=b; h++)
					ans += (f[h-a]*d[h])%mod;
				
				cout<<ans%mod<<endl;
			}
		}
		
	}
	
}
