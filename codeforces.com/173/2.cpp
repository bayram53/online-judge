# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <vector>
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n;
int d[1000009][3];
char c[1000009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&d[h][0],&d[h][1]);
	
	int p = d[0][0];
	c[0]='A';
	
	for(int h=1; h<n; h++)
	{
		if(abs(d[h][0]+p) <= 500)
			p += d[h][0] , c[h] = 'A';
		else
			p -= d[h][1] , c[h] = 'G';
	}
	
	if(abs(p) <= 500)
		printf("%s",c);
	
	else
	{
		p = -d[0][1];
		c[0]='G';
	
		for(int h=1; h<n; h++)
		{
			if(abs(d[h][0]+p) <= 500)
				p += d[h][0] , c[h] = 'A';
			else
				p -= d[h][1] , c[h] = 'G';
		}
		
		if(abs(p) <= 500)
			printf("%s",c);
		else
		printf("-1");
		
	}
}
