# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <limits.h>
# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n,k,ans=0,p=0;
int t1[100009],r,o=INF,t2[100009];
int d[100009][2],m=1;

int main()
{
	scanf("%d",&k);
	
	for(int h=0; h<k; h++)
		scanf("%d",&r),o=mi(r,o);
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t1[h]);
	sort(t1,t1+n);int u=n-1;
	
	for(int h=0; h<n; h++)
		t2[u--]=t1[h];
	
	while(1)
	{
		if(p>=n)
			break;
		
		if(n-p<o)
		{
			for(int h=p; h<n; h++)
				ans+=t2[h];
			break;
		}
		
		for(int h=p; h<o+p; h++)
			ans+=t2[h];
		p+=o+2;
	}
	
	printf("%d",ans);
}
