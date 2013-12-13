# include <stdio.h>
# include <algorithm>

using namespace std;

int n,k;
int t[109];
int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	sort(t,t+n);
		
	for(int h=0; h<2; h++)
	{
		if(h==0)
		{int k1=0;
			for(int h1=n-1; h1>-1; h1--)
				if(0<t[h1])
				{
					k1++;
					
				if(k1==k)
				{
					printf("%d %d",t[h1],t[h1]);
					return 0;
				}
			}
		}
		
		else
		{int k1=0;
			for(int j=n-1; j>-1; j--)
				if(0>t[j])
				{
					k1++;
					
					if(k1==k)
						{printf("%d %d",t[h],t[h]);return 0;}
				}
			
		}
		
	}
	
	printf("-1");
}
