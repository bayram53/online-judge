# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;


int n;

int main()
{
	scanf("%d",&n);
	
	if(n==1 || n==2)
		printf("-1");
		
	else
	{
		for(int h=n; h>0; h--)
			printf("%d ",h);
	}
	
}
