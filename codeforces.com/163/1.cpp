# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <string.h>
# include <limits.h>

# define INF INT_MAX
# define mi(x , y) (x < y  ? x  : y)

using namespace std;

int n,a=0;
char c[109];

int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	
	for(int h=0; h<n-1; h++)
		if(c[h]==c[h+1])
			a++;
			
		printf("%d",a);
}
