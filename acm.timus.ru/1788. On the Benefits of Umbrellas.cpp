# include <stdio.h>
# include <vector>
# include <functional>
# include <algorithm>
# include <limits.h>
# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n , m , ans = INF;
vector <int> g , b;

int main()
{
	scanf("%d %d",&n,&m);

	g.resize(n);
	b.resize(m);
	
	for(int h=0; h<n; h++)
		scanf("%d",&g[h]);
	
	for(int j=0; j<m; j++)
		scanf("%d",&b[j]);
	
	sort(b.begin(),b.end() , greater<int>());
	sort(g.begin(),g.end() , greater<int>());
	
	int f = n;
	
	if(n > m)
		f = m;
	
	for(int h=0; h<=f; h++)
	{
		int p = 0;
		
		for(int j=h; j<n; j++)
			p += g[j];
		
		for(int j=h; j<m; j++)
			p += b[j] * h;
		
		ans = mi(ans , p);
	}
	
	printf("%d",ans);
}
