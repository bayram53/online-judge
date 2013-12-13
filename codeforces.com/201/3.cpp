# include <stdio.h>

# define ma(x,y) (x>y ? x : y)

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int n, a, m, k;

int main()
{
	scanf("%d %d",&n,&k);
	
	m = k;
	
	for(int h=1; h<n; h++)
	{
		scanf("%d",&a);
		
		m = ma(m, a);
		
		k = gcd(k, a);
	}
	
	printf("%s\n",((m/k-n)%2 ? "Alice" : "Bob"));
}
