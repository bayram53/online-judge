# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <vector>

using namespace std;

int n,k,ans;
int d[100009];
int x,y,san;

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
		scanf("%d",&d[h]);
	
	while(y < n)
	{
		ans = max(y-x , ans);
		
		if(san + d[y] <= k)
			san += d[y++];
		else
			san -= d[x++];
	}
	
	ans = max(y-x ,ans);
	
	printf("%d",ans);
}
