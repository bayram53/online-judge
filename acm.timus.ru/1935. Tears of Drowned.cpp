# include <stdio.h>

int n,m,k,a;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		if(a > k)
			k = a;
		m += a;
	}
	
	printf("%d",m + k);
}
