# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,m;
int t[10009];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int j=0; j<n; j++)
	scanf("%d",&t[j]);
	
	sort(t,t+n);
}
