# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

int n,l=0,ans=-1;
int a,b,a1,b1;

int main()
{
	scanf("%d",&n);
	
	scanf("%d %d",&a,&b);
	
	for(int h=1; h<n; h++)
	{
		scanf("%d %d",&a1,&b1);
		
		if(a1!=a || b1!=b)
		{
			a=a1;
			b=b1;
			
			if(l+1>ans)
				ans=l+1;
			
			l=0;
		}
		
		else
			l++;
		
	}
	
	printf("%d",ans);
	
}
