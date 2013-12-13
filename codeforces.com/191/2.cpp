# include <stdio.h>

# define MAXN 10000009

int n,a;

int D[MAXN];

int main()
{
	scanf("%d",&n);
	
	D[1] = 1;
	
	for(int h=2; h<3162; h++)
		for(int j=h*h; j<2000000; j+=h)
				D[j] = 1;
				
	for(int h=2; h<2000000; h++)
	if(!D[h])
	{a++;
		printf("%d ",h);
		n--;
		if(!n)	break;
	}
	
	//printf("\n___%d",a);
}
