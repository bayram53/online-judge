# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,p;
int t[109];
char c[109][109];
int g[109][10];
int k[109][10];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%s",c[h]),t[h]=strlen(c[h]);
	
	
	for(int h=0; h<n; h++)
	{
		int l=0;
		p=t[h];
		
		for(int j=1; j<t[h]; j++)
			if(c[h][j-1]==':' && c[h][j]==':')
				p=j-1;
		
		for(int h1=0; h1<p; h1++)
		{
			if(c[h][h1]==':')
			{
				k[h][l+1]=h1+1;
				l++;
			}
			
			else
				g[h][l]++;
		}
		
		l=7;
		for(int h1=t[h]-1; h1>p+1; h1--)
		{
			if(c[h][h1]==':')
			{
				k[h][l]=h1+1;
				l--;
			}
			
			else
				g[h][l]++;
		}
		if(p!=t[h])
		k[h][l]=p+2;
		for(int j=0; j<8; j++)
		{
			for(int h1=0; h1<4-g[h][j]; h1++)
				printf("0");
			
			for(int o=k[h][j]; o<k[h][j]+g[h][j]; o++)
				printf("%c",c[h][o]);
			
			if(j!=7)
				printf(":");
		}
		printf("\n");
	}
}
