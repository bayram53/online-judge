# include <stdio.h>

int d[4][4];
int a[4][4];

int main()
{
	for(int h=1; h<4; h++)
		for(int j=1; j<4; j++)
			scanf("%d",&d[h][j]);
	
	for(int h=1; h<4; h++)
		for(int j=1; j<4; j++)
		{
			int k = d[h][j];
			
			a[h-1][j] += k;
			a[h+1][j] += k;
			a[h][j-1] += k;
			a[h][j+1] += k;
			a[h][j] += k;
		}
	
	for(int h=1; h<4; h++)
	{
		for(int j=1; j<4; j++)
			printf("%d",(a[h][j]+1)%2);
		printf("\n");
	}
	
}
