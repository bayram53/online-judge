# include <stdio.h>

int n, a, b, p = 0;

int D[109][3];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&D[h][0],&D[h][1]);
		a += D[h][0];
		b += D[h][1];
		if((D[h][1]%2 == 1  &&  D[h][0] %2 == 0)  ||  (D[h][0]%2 == 1  &&  D[h][1] %2 == 0))	p = 1;
	}
	
	if((a+b)%2 == 1)	printf("-1");
	
	else
	{
		if(a%2 == 0  &&  b % 2 == 0)	printf("0");
		else if(p)	printf("1");
		else 	printf("-1");
	}
}
