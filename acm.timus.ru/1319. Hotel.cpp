# include <stdio.h>

int n,san=1,x,y;
int t[109][109];

int main()
{
	scanf("%d",&n);
	
	for(int h=2*n-1; h>0; h--)
	{
		x=n-(h%n);
		y=0;
		if(h>=n){ x=0; y=h%n; }
		
		while(x<n && y<n)
		t[x++][y++]=san++;
		
	}
	
	for(int h=0; h<n; h++)
	{
		for(int j=0; j<n; j++)
		printf("%d ",t[h][j]);
		printf("\n");
	}
	getchar(); getchar();
}
