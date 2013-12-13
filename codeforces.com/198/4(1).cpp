# include <stdio.h>

# define MAXN 100009
# define ma(x,y) (x>y ? x : y)

int n, ans;

int D[MAXN];

int b_s(int l,int r,int x)
{
	if(r-l < 2)
	{
		if(D[r] < x)	return r;
		return l;
	}
	
	int mid = (l+r)/2;
	
	if(D[mid] < x)	return b_s(mid, r, x);
	
	return b_s(l, mid, x);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)	D[h] = MAXN;
	
	for(int h=0; h<n; h++)
	{
		int a;
		
		scanf("%d",&a);
		
		int k =  b_s(0, n-1, a);
		
		if(D[k+1] > a)	D[k+1] = a;
		
		ans = ma(k+1, ans);
	}
	
	printf("%d",ans);
}
