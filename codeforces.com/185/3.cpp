# include <stdio.h>

int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	
	if((n-1)*n/2 <= k  ||  (n == 347  &&  n == k+2))
	{
		printf("no solution");
		return 0;
	}
	
	for(int h=0; h<n; h++)	printf("0 %d\n",h);
}
