# include <iostream>
# include <string.h>
# include <algorithm>
# define mod 1000000007

using namespace std;

long long n,s,p=0,w=0,ans=0;
long long d[19];
long long f[19];
long long g[10];
bool r[19];

long long gcd(long long n,long long m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

long long fac(long long x,long long y)
{
	long long a=1,b=1;
	
	for(int h=2; h<=x; h++)
		b*=h;
	
	for(int h=y; h>y-x; h--)
	{
		int o=gcd(b,h),l;
		
		l=h/o;
		b/=o;
		a*=l;
		a%=mod;
	}
	
	
	
	return a;
}

long long so(long long x)
{
	long long l=0;
	
	for(int h=0; h<x; h++)
		if(h!=4 && h!=7)
			l++;
	
	return l;
}

void tap(long long x)
{
	if(x==p)
	{
		long long y=p;
		
		for(int h=0; h<p; h++)
			y-=r[h];
		
		for(int h=0; h<p; h++)
		{
			long long f=1;
			
			if(r[h]==0 && d[h]>7)
				f=2;
				
			else if(r[h]==0 && d[h]<5)
				f=0;
			
			if(r[h]==1)
				f*=so(d[h]);
		
			for(int j=0; j<h; j++)
				if((r[j]==1 && (d[j]==4 || d[j]==7)) || (r[j]==0 && (d[j]!=4 && d[j]!=7)))
					f=0;
			
			for(int j=h+1; j<p; j++)
			{
				if(r[j]==0)
					f*=2;
				
				else
					f*=8;
			}
			
			
			
			g[y]+=f;
		}
		
		
	}
	
	else
	{
		r[x]=0;
		tap(x+1);
		
		r[x]=1;
		tap(x+1);
	}
}

void tapmak(long long x,long long y,long long u)
{
	if(y==0)
	{
		long long r=0;
		
		for(int h=0; h<10; h++)
			r+=f[h]*h;
			
		for(int h=0; h<10; h++)
			if(f[h]>g[h])
				r=99;
		
		if(r<u)
		{
			long long m=6*5*4*3*2;
			
			for(int h=0; h<10; h++)
				if(f[h]!=0)
					m*=fac(f[h],g[h]),m%=mod;
			
			ans+=(m*g[u])%mod;
			ans%=mod;
		}
	}
	
	else
	{
		if(x>0)
			for(int h=0; h<=y; h++)
			{
				f[x]=h;
		
				for(int j=0; j<x; j++)
					f[j]=0;
		
				tapmak(x-1,y-h,u);
			}

		else
		{
			f[0]=y;
			tapmak(x,0,u);
		}
	}
}

int main()
{
	cin>>n;
	
	s=n;
	
	while(s!=0)
	{
		if(s%10==4 || s%10==7)
			w++;
		
		d[p++]=s%10;
		s/=10;
	}
	int e=p-1;
	for(int h=0; h<p/2; h++)
		swap(d[h],d[e]),e--;
	
	tap(0);
	
	g[0]--;
	g[w]++;
	
	for(int h=1; h<10; h++)
		if(g[h]!=0)
			tapmak(h-1,6,h),memset(f,0,sizeof(f));
	
	cout<<ans;
}
