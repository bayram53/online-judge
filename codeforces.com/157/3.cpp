# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

using namespace std;

int ans=-1;
char c[100009];

int main()
{
	scanf("%s",c);
	
	int n=strlen(c);
	
	for(int h=0; h<n; h++)
		if(c[h]=='0')
			{ans=h;break;}
			
	if(ans==-1)
		for(int h=0; h<n-1; h++)
			printf("1");
			
	else
		for(int h=0; h<n; h++)
			if(ans!=h)
				printf("%c",c[h]);
}
