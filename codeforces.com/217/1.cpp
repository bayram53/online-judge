# include <stdio.h>
# include <string.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)

using namespace std;

int r1, c1, r2, c2;
int G[12][21];
int x[][2] = {{-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

int main()
{
	for(int h=1; h<9; h++)
		for(int j=1; j<9; j++)
			G[h][j] = 12;
	
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	
	if(r1 == r2  &&  c1 == c2)	{printf("0 0 0"); return 0;}
	else if(r1 == r2)	printf("1");
	else if(c1 == c2)	printf("1");
	else printf("2");
	printf(" ");
	
	if((r1%2 + c1)%2 != (r2%2 + c2)%2)	printf("0 ");
	
	else
	{
		G[r1][c1] = 0;
		
		for(int h=0; h<3; h++)
			for(int i=1; i<9; i++)
				for(int j=1; j<9; j++)
					for(int tmp=0; tmp<4; tmp++)
					{
						int a = i, b = j;
						while(a < 9  &&  a > 0  &&  b < 9  &&  b > 0)
						{
							G[a][b] = mi(G[a][b], G[i][j]+1);
							
							a += x[tmp][0];
							b += x[tmp][1];
						}
					}
			
			/*for(int i=1; i<9; i++)
			{
				for(int j=1; j<9; j++)	printf("%d ",G[i][j]);
				printf("\n");
			}*/
		printf("%d ",G[r2][c2]);
	}
	
	printf("%d",abs(r1-r2)+abs(c1-c2) - mi(abs(c1-c2), abs(r1-r2)));
}
