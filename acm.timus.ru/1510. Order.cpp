# include <stdio.h>
# include <algorithm>

using namespace std;

int n;
int x,a;
int t[500009];
int ans=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	sort(t,t+n);
	
	x=0;
	
	for(int h=1; h<n; h++)
		if(t[h-1]!=t[h])
		{
			if(ans<h-x)
				a=t[h-1];
			
			ans=max(ans,h-x);
			x=h;
		}
			
	ans=max(ans,n-x);
	
	if(n-x==ans)
		a=t[n-1];
	
	printf("%d",a);
}
