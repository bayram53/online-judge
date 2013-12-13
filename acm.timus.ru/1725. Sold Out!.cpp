# include <stdio.h>
# define ma(x,y) (x>y ? x : y)

int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	
	if(ma(k-1,n-k)-2<0)
		printf("0");
		
	else
		printf("%d",ma(k-1,n-k)-2);
}
