# include <stdio.h>

int a;
char c;

int main()
{
	scanf("%d%c",&a,&c);
	
	if(a<3)
	{
		if(c=='A' || c=='D')
			printf("window");
		
		else
			printf("aisle");
	}
	
	else if(a<21)
	{
		if(c=='A' || c=='F')
			printf("window");
			
		else if(c=='B' || c=='C' || c=='D' || c=='E')
			printf("aisle");
			
		else
			printf("neither");
	}
	
	else
	{
		if(c=='A' || c=='K')
			printf("window");
		
		else if(c=='G' || c=='C' || c=='D' || c=='H')
			printf("aisle");
			
		else
			printf("neither");
	}
	
}
