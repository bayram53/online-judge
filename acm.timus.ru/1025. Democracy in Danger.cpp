# include <stdio.h>
# include <algorithm>
# include <stdlib.h>

using namespace std;

int n,t[109],ans;

int main()
{
	scanf("%d",&n);
	for(int h=0; h<n; h++) scanf("%d",&t[h]);
	
	sort(t,t+n);
	
	if(n%2==0) n/=2;
	else n=n/2+1;
	
	for(int h=0; h<n; h++)
	ans+=t[h]/2+1;
	
	printf("%d",ans);
}
