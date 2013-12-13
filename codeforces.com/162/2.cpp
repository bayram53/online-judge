# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <vector>
# include <limits.h>

using namespace std;

int t[100009];
int n,a1,a2,pos;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	for(int h=0; h<n; h++)
	{
		a1+=t[h]-pos+1;
		
		if(t[h]>t[h+1] && h+1!=n)
			a1+=t[h]-t[h+1]+1,pos=t[h+1];
		else if(h!=n-1)
			pos=t[h],a1++;
	}
	pos=0;
	a2=n-1;
	
	for(int h=n-1; h>-1; h--)
	{
		a2+=t[h]-pos+1;
		
		if(t[h]>t[h-1] && h-1!=0)
			a2+=t[h]-t[h-1]+1,pos=t[h-1];
		else if(h!=0)
			pos=t[h],a2++;
	}
	
	printf("%d",a1);
}
