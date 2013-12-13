# include <stdio.h>
# include <iostream>
# define mod 1000000007
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)
typedef long long llint;

using namespace std;

llint a,b,n,x,y,ol;

llint d[1000009],c[1000006];

long long ans = 1;

llint di[1000006];

llint k1[1000009],k2[1000009];

llint tap(llint x)
{
	llint  p = 1;
	
	while(x)
	{
		if(x % 10 != a   &&  x % 10 != b)	p = 0;
		x /= 10;
	}
	
	return p;
}

llint big_mod(llint x,llint y)
{
	if(y == 0)	return 1;
	if(y == 1)	return x;
	
	llint  p = big_mod(x , y/2);
	
	if(y%2 == 0)	return (p*p)%mod;
	return (((p*p)%mod)*x)%mod;
}

int main()
{
	for(llint h=2; h<1000001; h++)
	{
		if(!di[h])	di[h] = h;
		
		if(h > 1000)	continue;
		
		for(llint j=h*h; j<1000001; j+=h)
			if(!di[j])	di[j] = h;
	}
	
	cin>>a>>b>>n;
	
	for(llint h=0; h<=n; h++)
		if(tap(h*a+(n-h)*b))
		{printf("%lld %lld\n",h,n-h);
			d[h+1]++;
			c[1]++;
			c[n-h+1]--;ol = 1;
		}
	
	for(llint h=1; h<=n; h++)
	{
		x += d[h]; d[h] = x;
		y += c[h]; c[h] = y;
		llint o = mi(c[h] , d[h]);
		d[h] -= o;
		c[h] -= o;
		
		o = h;
		
		while(o != 1)
		{
			k1[di[o]]+=d[h];
			k2[di[o]]+=c[h];
			o/=di[o];
		}
	}
	
	for(llint h=1; h<=n; h++)
	{//printf("%lld %lld__",k1[h],h);
		k1[h] -= k2[h];
		ans *= big_mod(h , k1[h]);
		ans  %= mod;
	}
	
	if(!ol)printf("0");
	else 	cout<<ans;
}
