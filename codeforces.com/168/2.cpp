# include <stdio.h>
# include <algorithm>
# define mi(x,y) (x<y ? x : y)

using namespace std;

int ans;
int n,m;
int d1[109][109];
int d2[109][109];
char f[109][109];

int tap(int x1,int y1,int x2,int y2)
{
	int a = abs(x2 - x1) + abs(y2 - y1);
	
	if(x2 < x1)
		swap(x2,x1) , swap(y1,y2);
	
	if(y1 < y2  &&  (a == d2[x2][y1] - d2[x1-1][y1] + d1[x2][y2] - d1[x2][y1-1] - 2  ||  a == d1[x1][y2] - d1[x1][y1-1] + d2[x2][y2] - d2[x1-1][y2] - 2))
		return 0;
			
	if(y1 >= y2  && (a == d2[x2][y2] - d2[x1-1][y2] + d1[x1][y1] - d1[x1][y2-1] - 2  ||  a == d2[x2][y1] - d2[x1-1][y1] + d1[x2][y1] - d1[x2][y2-1] - 2))
		return 0;
	
	return 1;
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=1; h<=n; h++)
	{
		scanf("\n");
		for(int j=1; j<=m; j++)
		{
			scanf("%c",&f[h][j]);
			
			if(f[h][j] == 'B')
				d2[h][j] = d1[h][j] = 1;
		}
	}
	
	for(int h=1; h<=n; h++)
		for(int j=1; j<=m; j++)
			d1[h][j] += d1[h][j-1];
			
	for(int h=1; h<=m; h++)
		for(int j=1; j<=n; j++)
			d2[j][h] += d2[j-1][h];
	
	for(int h1=1; h1<=n; h1++)
		for(int j1=1; j1<=m; j1++)
			for(int h2=1; h2<=n; h2++)
				for(int j2=1; j2<=m; j2++)
					if(f[h1][j1] == 'B'  &&  f[h2][j2] == 'B'  &&  tap(h1,j1,h2,j2))
					{
						//printf("%d %d %d %d\n",h1,j1,h2,j2);
						printf("NO");
						return 0;
					}
	printf("YES");
}
