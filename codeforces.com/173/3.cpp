# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <vector>

using namespace std;

char c1[1000009];
char c2[1000009];

int main()
{
	scanf("%s\n%s",c1,c2);
	
	int n = strlen(c1);
	int a=0,b=0;
	
	for(int h=0; h<n; h++)
		a += c1[h]-48;
	
	int m = strlen(c2);
	
	for(int j=0; j<m; j++)
		b += c2[j]-48;
	
	if(n != m  || (a == 0  &&  b != 0)  ||  (b == 0  &&  a != 0))
		printf("NO");
	else
		printf("YES");
}
