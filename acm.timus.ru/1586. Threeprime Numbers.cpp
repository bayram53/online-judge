# include <stdio.h>
# define mod 1000000009
# include <algorithm>
# include <string.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

long long d[10009][109];
int n;
long long ans=0,a,b=9;
int v[1009];

int main()
{
	scanf("%d",&n);
	
	for(int h=100; h<1000; h++)
	{
		bool p=0;
		
		for(int j=2; j<=int(sqrt(h*1.0))+1; j++)
			if(h%j==0)
				p=1;
		
		if(p==0)
			v[h]=1,d[3][h%100]++;
	}
	
	for(int h=4; h<=n; h++)
		for(int j=0; j<100; j++)
			for(int i=0; i<10; i++)
				if(v[i+j*10]==1)
					d[h][i+(j%10)*10]+=d[h-1][j],d[h][i+(j%10)*10]%=mod;
	
	for(int h=0; h<100; h++)
		a+=d[n][h],a%=mod;
	
	printf("%lld",a);
}
