# include <stdio.h>
# include <algorithm>

using namespace std;

int n,a,ans;

int s[100009] , *t[1009];

int d[1009];

int tap(int id,int lo,int hi)
{
	return lower_bound(t[id] , t[id]+d[id] , lo) - lower_bound(t[id] , t[id]+d[id] , hi);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&d[h]);
		t[h] = s+a;
		for(int j=0; j<d[h]; j++)	scanf("%d",&t[h][j]);
		sort(t[h] , t[h]+d[h]);
		a += d[h];
	}
	
	for(int h=0; h<n; h++)
		for(int j=1; j<d[h]; j++)
		{
			int x = t[h][j];
			int y = t[h][j-1];
			ans += tap((h+1)%n , x , y) != tap((h-1+n)%n , x , y);
		}
	
	printf("%d\n",ans);
}
