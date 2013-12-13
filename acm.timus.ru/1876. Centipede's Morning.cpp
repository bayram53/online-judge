# include <stdio.h>

int a,b;

int main()
{
	scanf("%d %d",&a,&b);
	
	if(2*a+39<2*b+40)
		printf("%d",2*b+40);
	
	else
		printf("%d",2*a+39);
}
