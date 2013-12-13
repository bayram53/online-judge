# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <limits.h>
# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n,k,a,m=INF,ans=0,o=0;
int t[100009];

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]),m=mi(m,abs(t[h]));
	
	sort(t,t+n);
	
	for(int h=0; h<n; h++)
	{
		if(t[h]>=0 || o==k)
			break;
		t[h]*=-1;
		o++;
	}
	
	for(int h=0; h<n; h++)
		ans+=t[h];
	
	if((k-o)%2==1)
		ans-=2*m;
	printf("%d",ans);
}
