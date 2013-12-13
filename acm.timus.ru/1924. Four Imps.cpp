# include <stdio.h>

int n;

int main()
{
	scanf("%d",&n);
	
	if(n*(n+1)/2%2==0)
		printf("black");
		
	else
		printf("grimy");
}
