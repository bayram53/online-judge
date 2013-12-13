# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

int n,a1;
int a=0,b=0,c=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a1);
		
		if(h%3==0)
			a+=a1;
			
		else if(h%3==1)
			b+=a1;
		
		else
			c+=a1;
	}

	if(a>b && a>c)
		printf("chest");
		
	else if(a<b && b>c)
		printf("biceps");
		
	else
		printf("back");
}	
