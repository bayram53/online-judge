# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
char c[1000000];
int n,x=0,y=0;

using namespace std;

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=0; h<n; h++)
	{
		if(c[h]=='x')
			x++;
		
		else
			y++;
	}
	
	if(x>y)
		for(int h=0; h<x-y; h++)
			printf("x");
			
	else
		for(int j=0; j<y-x; j++)
			printf("y");
}	
