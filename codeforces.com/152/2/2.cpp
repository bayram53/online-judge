# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n;
int m=16;

int main()
{
	scanf("%d",&n);
	
	if(n==1 || n==2)
	{
		printf("-1");
		return 0;
	}
	
	if(n==3)
		{printf("210");return 0;}
	
	for(int h=4; h<n; h++)
	{
		m*=10;
		m%=21;
	}
	
	printf("1");
	
	for(int h=0; h<n-4; h++)
		printf("0");
		
	if(21-m<10)
		printf("0");
		
	printf("%d",21-m);
	printf("0");
}
