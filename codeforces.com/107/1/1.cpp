# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,m,ans=0;
int t[109][109];
bool vis[473];
int a[2345],max1;
char c[564];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",c);
		for(int j=0; j<m; j++)
		t[h][j]=c[j]-48;
	}
	
	for(int h=0; h<m; h++)
	{
		max1=-1;
		for(int j=0; j<n; j++)
		if(max1<t[j][h])
			max1=t[j][h];
		a[h]=max1;
	}
	
	for(int h=0; h<n; h++)
	for(int j=0; j<m; j++)
	if(vis[h]==0 && a[j]==t[h][j])
	{
		vis[h]=1;
		ans++;
	}
	
	printf("%d",ans);
}
