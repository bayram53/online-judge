# include <stdio.h>

int n,x,y;
int t[109][109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	for(int j=0; j<n; j++)
	scanf("%d",&t[h][j]);
	
	printf("%d",t[0][0]);
	
	for(int h=1; h<n*2; h++)
	{
		x=h%n; y=0;
		if(h/n==1){ x++; y=n-1; }
		
		
		while((x>=0 && h<n) || (x<n && h>=n))
		{
			
			if(h<n){printf(" %d",t[x][y]); y++; x--;}
			
			else { printf(" %d",t[y][x]); y--; x++; }
		}
	}
	getchar(); getchar();
}
