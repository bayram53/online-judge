# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <iostream>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

int n;
char s[10009];
int d[30];

int main()
{
	scanf("%s",s);
	
	n = strlen(s);
	
	for(int h=0; h<n; h++)	
		d[s[h]-97]++;
	
	n = 0;
	
	for(int h=0; h<30; h++)
		if(d[h] % 2 == 1)
			n++;
	
	if(n % 2 == 0  &&  n)
		printf("Second");
	else
		printf("First");
}
