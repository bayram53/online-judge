# include <stdio.h>
# include <algorithm>

using namespace std;

int n,m,ans=-999;
int t[409][409];

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
		for(int j=1; j<=n; j++)
			scanf("%d",&t[h][j]);
			
	for(int h=1; h<=n; h++)
		for(int j=1; j<=n; j++)
			t[h][j]+=t[h][j-1];
		
	for(int h=1; h<=n; h++)
		for(int j=h; j<=n; j++)
		{
			int ma=-999,a=0;
			for(int i=1; i<=n; i++)
			{
				a+=t[i][j]-t[i][h-1];
				
				ma=max(a,ma);
				
				a=max(0,a);
				
			}
			
			ans=max(ma,ans);
		}
		
	printf("%d",ans);
}
