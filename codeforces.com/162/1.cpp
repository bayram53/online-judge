# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <vector>
# include <limits.h>

using namespace std;

int n,m,a=0;
char c1[59],c2[59];

int main()
{
	scanf("%s %s",c1,c2);
	
	n=strlen(c1);
	m=strlen(c2);
	
	for(int h=0; h<m; h++)
	{
		if(c2[h]==c1[a])
			a++;
	}
	
	printf("%d\n",a+1);
	
}
