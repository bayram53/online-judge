# include <stdio.h>
# include <math.h>

typedef long long llint;

llint n,k=1;

int main()
{
	scanf("%I64d",&n);
	
	for(llint j=1; j<37; j++)
	{
		k *= 3;
		
		if(n%k != 0){printf("%I64d",n/k+1);return 0;}
	}
	
	
}
