# include <stdio.h>

int t[1000];
int ans=0,n,m;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&m);
		t[m]++;
	}
	
	for(int h=0; h<1000; h++)	
		ans+=t[h]/4;
		
	printf("%d",ans);
}
