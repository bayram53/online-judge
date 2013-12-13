# include <stdio.h>
# include <algorithm>

using namespace std;

# define MAXN 1000009
# define ma(x,y) (x>y ? x : y)

int n, k, ans = 1;

int D[MAXN], p[30];

int main()
{
	p[0] = 1;
	
	for(int h=1; h<20; h++)	p[h] = p[h-1]*2;
	
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)	scanf("%d",&D[h]);
	
	sort(D, D+n);
	
	for(int h=2; h<MAXN; h++)
	{
		int a = 0;
		
		for(int j=h; j<MAXN; j+=h)
			if(a < n  &&  D[a] >= j  &&  D[a]-k <= j)
				for(int i = 18; i>-1; i--)
					if(a+p[i] <= n  &&  D[a+p[i]-1]-k <= j)
						a += p[i];
		
		if(a == n)	ans = h;
	}
	
	printf("%d\n",ans);
}
