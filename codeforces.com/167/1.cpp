# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <stdlib.h>

using namespace std;

int n , ans;
int a,b;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&a) , b += a;
	
	for(int h=1; h<6; h++)
		if((b + h) % (n + 1) == 1)
			ans++;
		
	printf("%d",5 - ans);
}
