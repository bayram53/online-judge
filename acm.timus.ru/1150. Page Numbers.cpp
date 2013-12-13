# include <stdio.h>
# include <algorithm>
# include <math.h>

using namespace std;

long long n;
int f[10];
long long ans[11];

long long sayla(long long x,long long y)
{
	long long s=1;
	
	for(int h=x; h>x-y; h--)
		s*=h;
		
	for(int h=2; h<=y; h++)
		s/=h;
	
	return s;
}

void tap0(long long x,int y=-1)
{
	for(int h=0; h<10; h++)
	{
		for(int j=1; j<=x; j++)
		if(h!=0 || j!=x)
		{
			long long s=(long long)pow(9.0,(x-j)*1.0);
			
			if(h!=0)
			{
				if(y==-1)
				ans[h]+=s*sayla(x,j)*j;
			}
			else
				ans[h]+=s*sayla(x-1,j)*j;
		}
	}
	
	if(x-1>0)
		tap0(x-1,0);
}

void tap(long long x)
{
	for(int h=0; h<10; h++)
	{
		for(int j=1; j<=x; j++)
		{
			long long s=(long long)pow(9.0,(x-j)*1.0);
			
			ans[h]+=s*sayla(x,j)*j;
		}
	}
}

int main()
{
	scanf("%lld",&n);
	
	int	k=n,nr=0;
	
	while(k!=0)
	{
		f[nr++]=k%10;
		ans[k%10]++;
		k/=10;
	}
	
	int d=nr-1;
	
	for(int h=0; h<nr/2; h++)
		swap(f[h],f[d--]);
	
	for(int h=0; h<nr; h++)
	{
		int o=0;
		
		if(h==0)
			o++,tap0(nr-1);
		
		for(int j=o; j<f[h]; j++)
		{
			ans[j]+=(long long)pow(10.0,(nr-h-1)*1.0);
			
			for(int i=0; i<h; i++)
				ans[f[i]]+=(long long)pow(10.0,(nr-h-1)*1.0);
			
			tap(nr-h-1);
		}
	}
	
	for(int h=0; h<10; h++)
		printf("%lld\n",ans[h]);
}
