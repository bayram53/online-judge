# include <stdio.h>

int n, k;

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
	{
		for(int j=0; j<n; j++)
		{
			if(h == j)	printf("%d ",k);
			else 	printf("0 ");
		}
		
		printf("\n");
	}
}
