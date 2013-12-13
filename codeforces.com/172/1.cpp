# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits.h>
# include <stdlib.h>
# include <ctype.h>

using namespace std;

char c[1009];

int main()
{
	scanf("%s",c);
	
	if(c[0] > 96)
		c[0] -= 97-65;
	
	printf("%s",c);
}
