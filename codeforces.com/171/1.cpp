# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <vector>

using namespace std;

int x,y;
int a,b,ans,n=1;

int main()
{
	scanf("%d %d",&x,&y);
	
	if(x == 0  &&  x == y)
	{
		printf("0");
		return 0;
	}
	
	while(1)
	{
		for(int h=0; h<n; h++)
			if(++a == x  &&  y == b)
			{printf("%d",ans);return 0;}
		
		ans++;
		
		for(int h=0; h<n; h++)
			if(++b == y  &&  a == x)
				{printf("%d",ans);return 0;}
		
		n++;
		ans++;
		
		for(int h=0; h<n; h++)
			if(--a == x  &&  b == y)
				{printf("%d",ans);return 0;}
		
		ans++;
		
		for(int h=0; h<n; h++)
			if(--b == y  &&  a == x)
				{printf("%d",ans);return 0;}
		n++;
		ans++;
	}
}
