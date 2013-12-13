# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

using namespace std;

int n;
int ans=0;
char t[10][10];

int main()
{
	for(int h=0; h<8; h++)
		scanf("%s",t[h]);
	
	for(int h=0; h<8; h++)
	for(int j=1; j<8; j++)
		if(t[h][j-1]==t[h][j])
			ans=1;
	
	if(ans==1)
		printf("NO");
		
	else
		printf("YES");
}
