# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

struct mal
{
	int a,b;
};




int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
		
	else
		return m.a-n.a;
}

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	
}

//qsort(t,n,sizeof(mal),so);
