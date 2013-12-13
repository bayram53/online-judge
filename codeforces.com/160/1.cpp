# include <stdio.h>
# include <iostream>

using namespace std;

int n,k,ans=0,a;

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		int o=0;
		while(a!=0)
		{
			if(a%10==7 || a%10==4)
				o++;
			a/=10;
		}
		
		if(o<=k)
			ans++;
	}
	
	printf("%d",ans);
}
