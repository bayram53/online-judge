# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

struct mal
{
	int a,b;
};


int n,x,y;
int a,b,c;
int t[2];

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
	scanf("%d",&n);
	
	for(int h=0 ;h<n; h++)
	{
		scanf("%d %d %d",&a,&b,&c);
		t[a-1]+=b;
		if(a%2==0)
			y+=5;
		else
			x+=5;
	}
	
	if(t[0]>=x)
		printf("LIVE\n");
		
	else
		printf("DEAD\n");
		
	if(t[1]>=y)
		printf("LIVE");
		
	else
		printf("DEAD");
}


//qsort(t,n,sizeof(mal),so);
