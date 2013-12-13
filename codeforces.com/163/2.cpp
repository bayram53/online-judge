# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <string.h>
# include <limits.h>

# define INF INT_MAX
# define mi(x , y) (x < y  ? x  : y)

using namespace std;

char c[109];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	
	scanf("%s",c);
	
	for(int h=0; h<m; h++)
	{
		for(int j=0; j<n-1; j++)
			if(c[j]=='B' && c[j+1]=='G')
				swap(c[j],c[j+1]),j++;
	}
	
	printf("%s",c);
}
