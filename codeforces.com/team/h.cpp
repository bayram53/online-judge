# include <stdio.h>
# include <algorithm>
# include <functional>

using namespace std;

int n, D[20009], t;

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		int ans = 0;
		scanf("%d",&n);
		
		for(int h=0; h<n; h++)	scanf("%d",&D[h]);
		
		sort(D, D+n, greater<int>());
		
		for(int h=2; h<n; h+=3)	ans += D[h];
		
		printf("%d\n",ans);
	}
	
}
