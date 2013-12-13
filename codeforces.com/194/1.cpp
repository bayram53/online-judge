# include <stdio.h>

int n;

int d[109][109] , l[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		int i = 0;
		
		if(h%2)
			for(int j=1; j<=n; j++)
				d[i][l[i]++] = h*n+j , i++;
		else
			for(int j=0; j<n; j++)
				d[i][l[i]++] = (h+1)*n-j , i++;
	}
	
	for(int h=0; h<n; h++)
	{
		for(int j=0; j<l[h]; j++)	printf("%d ",d[h][j]);
		printf("\n");
	}
}
