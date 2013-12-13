# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <vector>
# include <limits.h>

using namespace std;

char c[1000009];
int d[1000009];
int a=0,b;

int main()
{
	scanf("%s",c);
	
	int n=strlen(c);
	
	b=n-1;
	
	for(int h=0; h<n; h++)
	{
		if(c[h]=='l')
			d[b--]=h+1;
		else
			d[a++]=h+1;
	}
	
	for(int h=0; h<n; h++)
		printf("%d\n",d[h]);
}
