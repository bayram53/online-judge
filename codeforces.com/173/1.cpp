# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <vector>

using namespace std;

int n,a;
char c[9];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",c);
		
		if(c[1] == '-')
			a--;
		else
			a++;
	}
	
	printf("%d",a);
}
