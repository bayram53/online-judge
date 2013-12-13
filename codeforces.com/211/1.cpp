# include <stdio.h>

int n, p = 1;

int main()
{
	scanf("%d",&n);
	
	while(n  ||  p)
	{p = 0;
		int a = n%10;
		if(a >= 5)	printf("-O|"), a-= 5;
		else 	printf("O-|");
		for(int h=0; h<a; h++)	printf("O");
		printf("-");
		for(int j=a; j<4; j++)	printf("O");
		printf("\n");
		n /= 10;
	}
}
