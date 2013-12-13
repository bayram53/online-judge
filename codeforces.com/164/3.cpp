# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <string.h>
# include <limits.h>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

int n,m,ans;

int main()
{
	scanf("%d %d",&n,&m);
	
	ans=mi(n,m)+1;
	
	int x=n,y=0;
	
	printf("%d\n",ans);
	
	for(int h=0; h<ans; h++)
		printf("%d %d\n",x,y),x--,y++;
}
