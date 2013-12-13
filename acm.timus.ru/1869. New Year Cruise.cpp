# include <stdio.h>
# include <algorithm>
# include <string.h>

using namespace std;

int n,ans=0,cur;
int t[109][109],d[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			scanf("%d",&t[h][j]);
	
	for(int h=0; h<n; h++)
	{
		cur-=d[h];
		
		for(int j=h+1; j<n; j++)
		{
			d[j]+=t[h][j];
			cur+=t[h][j];
			
			int k=cur/36;
			if(cur%36!=0)
				k++;
			ans=max(k,ans);
		}
	}
	
	cur=0;
	memset(d,0,sizeof(d));
	
	for(int h=n-1; h>-1; h--)
	{
		cur-=d[h];
		
		for(int j=h-1; j>-1; j--)
		{
			d[j]+=t[h][j];
			cur+=t[h][j];
			
			int k=cur/36;
			if(cur%36!=0)
				k++;
			ans=max(k,ans);
		}
	}
		
	printf("%d",ans);
}
