# include <stdio.h>

int n,ans=0,k=0;
int t[2009];
int g[2009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	scanf("%d",&t[h]);
	
	for(int h=0; h<n; h++)
	{
		int a=t[h];
		
		while(a!=-1)
		{
			if(g[a]!=0)
			{
				g[h+1]+=g[a]+1;
				break;
			}
			
			a=t[a-1];
			g[h+1]++;
		}
	}
	
	for(int h=1; h<=n; h++)
		if(ans<g[h])
			ans=g[h];
	
	
	printf("%d",ans+1);
}
