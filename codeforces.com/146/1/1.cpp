# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

char a[109];
bool g[30];
int ans=0;


int main()
{
	scanf("%s",a);
	
	int j=strlen(a);

	
	for(int h=0; h<j; h++)
		g[a[h]-97]=1;
		
	for(int h=0; h<29; h++)
	if(g[h]==1)
		ans++;
		
	if(ans%2==0)
		printf("CHAT WITH HER!");
		
	
	else
		printf("IGNORE HIM!");
}
