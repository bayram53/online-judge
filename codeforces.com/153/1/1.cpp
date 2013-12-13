# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

int n,m,ans=0;
int t[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	for(int h=0; h<n; h++)
	{
		for(int j=h; j<n; j++)
	{m=t[h];
		for(int k=h; k<=j; k++)
		m=m^t[k];
		
		if(ans<m)
			ans=m;
	}
		
	}
	
	printf("%d",ans);
}
