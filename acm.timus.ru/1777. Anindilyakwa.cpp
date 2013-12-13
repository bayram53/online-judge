# include <stdio.h>
# include <limits.h>
# include <algorithm>
# define INF LLONG_MAX

using namespace std;

struct mal
{
	long long a,b,c;
};

long long t[100],n=3;

mal bil()
{
	mal d;
	d.c=INF;
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			if(h!=j && abs(t[h]-t[j])<d.c)
				d.c=abs(t[h]-t[j]),d.a=t[h],d.b=t[j];
	
	return d;
		
}

int main()
{
	scanf("%lld %lld %lld",&t[0],&t[1],&t[2]);
	
	while(bil().c!=0)
	{
		mal s=bil();
		t[n++]=s.c;
	}
	
	printf("%lld",n-2);
}
