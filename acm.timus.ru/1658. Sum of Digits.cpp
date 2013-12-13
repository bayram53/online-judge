# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <limits.h>
# include <string.h>
# include <stdlib.h>

# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

using namespace std;

int m,n,a,b;
int t[909][8109][2];

int main()
{
	scanf("%d",&m);
	
	for(int i=9; i>0; i--)
		for(int h=0; h<901; h++)
			for(int j=0; j<8101; j++)
				if((h==0 && j==0) || (h+i<901 && j+(i*i)<8101 && t[h][j][0]!=0 && (t[h+i][j+(i*i)][0]>=t[h][j][0]+1  || t[h+i][j+(i*i)][0]==0)))
					t[h+i][j+(i*i)][0]=t[h][j][0]+1,t[h+i][j+(i*i)][1]=i;
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		
		if(a > b  ||  a > 900  ||  t[a][b][0] > 100  ||  b > 8100  ||  t[a][b][0] == 0)
			{printf("No solution\n");continue;}
		
		int f[109],p=0;
		
		while(a>0)
		{
			f[p++]=t[a][b][1];
			
			a-=f[p-1];
			b-=(f[p-1]*f[p-1]);
		}
		
		for(int j=0; j<p; j++)
			printf("%d",f[j]);
		
		printf("\n");
	}
}
