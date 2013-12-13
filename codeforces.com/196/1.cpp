# include <stdio.h>
# include <algorithm>

using namespace std;

# define mi(x,y) (x<y ? x :y)

int D[1000],n,m,ans=457345;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)	scanf("%d",&D[h]);
	
	sort(D , D+m);
	
	for(int h=n-1; h<m; h++)	ans = mi(ans,D[h]-D[h-n+1]);
	
	printf("%d\n",ans);
}
