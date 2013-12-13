# include <stdio.h>

int n;

void gorkez1(int x)
{
	for(int h=1; h<=x; h++)	
	{
		if(h%2==0)
			printf("-");
			
		else if(h!=1)
			printf("+");
		
		printf("sin(%d",h);
	}
	
	for(int h=0; h<x; h++)
		printf(")");
	
}

void gorkez2(int y)
{
	for(int h=0; h<y-1; h++)
		printf("(");
	
	for(int h=0; h<y-1; h++)
	{
		gorkez1(h+1);
		printf("+%d)",y-h);
	}
	
	gorkez1(y);
	printf("+1");
}

int main()
{
	scanf("%d",&n);
	
	gorkez2(n);
	

	
}
