# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <iostream>
# include <limits.h>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

int n,k;
int ans = -1*INF;
int a,b;

int main()
{
	scanf("%d %d",&n,&k);
	
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		
		if(k >= b)
			ans = max(ans , a);
		else
			ans = max(ans , a-b+k);
		
	}
	
	printf("%d",ans);
}
