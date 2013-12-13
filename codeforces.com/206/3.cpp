# include <stdio.h>
# include <limits.h>

# define MAXN 100009
# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

int n, l, r, ql, qr, top, ans = INF;

int D[MAXN], d0[MAXN];

int main()
{
	scanf("%d %d %d %d %d",&n,&l,&r,&ql,&qr);
	
	for(int h=1; h<=n; h++)	scanf("%d",&D[h]), top += D[h], D[h] += D[h-1];
	
	for(int h=0; h<=n; h++)
	{
		int k = 0;
		int a = n-h;
		
		if(a > h)	k += (a-h-1)*qr;
		if(h > a)	k += (h-a-1)*ql;
		k += D[h]*l + (top-D[h])*r;
		ans = mi(k, ans);
	}
	
	printf("%d",ans);
}
