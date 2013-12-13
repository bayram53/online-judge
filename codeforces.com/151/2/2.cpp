# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

int n,a,ans=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		ans+=a;
	}
	
	if(ans%n==0)
		printf("%d",n);
		
	else
		printf("%d",n-1);
}
