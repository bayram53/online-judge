# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <string.h>
# include <limits.h>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

int n,ans;
int t[90][2];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&t[h][0],&t[h][1]);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			if(h!=j && t[h][0]==t[j][1])
				ans++;
				
	printf("%d",ans);
}
