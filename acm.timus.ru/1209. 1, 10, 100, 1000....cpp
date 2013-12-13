# include <stdio.h>
# include <math.h>

long long n,b;
long long san=1,j,d=1;
long long a[65539];

int main()
{
	scanf("%lld",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%lld",&b);
		long long g=(b-1)*2;
		double san1=sqrt((double)g);
		
		if(g==(long long)san1*(long long)(san1+1))
		a[h]=1;
		
		san=1; d=1;
	}
	
	for(int h=0; h<n; h++) printf("%lld ",a[h]);
}
