# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <stdlib.h>
# include <iostream>
# include <limits.h>

using namespace std;

int n;
char c[30];
bool d[30][30];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",c);
		
		int k = strlen(c);
		
		for(int j=0; j<k; j++)
		{
			d[c[j]-97][0] = 1;
			
			if(j != k-1)
				d[c[j]-97][c[j+1]-96] = 1;
		}
	}
	
	for(int h=0; h<26; h++)
		if(d[h][0] == 0)
			{printf("%c",char(h+97));return 0;}
		
	for(int h=0; h<26; h++)
		for(int j=1; j<27; j++)	
				if(d[h][j] == 0)
				{
					printf("%c%c",char(h+97),char(j+96));
					
					return 0;
				}
}
