# include <stdio.h>

# define mod 1000000000
typedef long long llint;

llint n,ans,m;

llint b_mod(llint x,llint y)
{
	if(y == 1)
		return x;
	
	llint d = b_mod(x , y/2);
	
	if(y % 2 == 0)
		return (d * d) % mod;
	return (x * d * d) %mod;
}

int main()
{
	scanf("%lld",&n);
	
	ans+= 1 + b_mod(2 , n) + b_mod(3 , n) + b_mod(4 , n);
	
	while(!(ans % 10 ))
	{
		m++;
		ans /= 10;
	}
	
	printf("%lld",m);
}
