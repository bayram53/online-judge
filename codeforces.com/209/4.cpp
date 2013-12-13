# include <stdio.h>
# include <limits.h>

# define MAXN 300009
# define INF INT_MAX
# define mi(x,y) (x<y ? x : y)

int n, ans = 0, p, k1, l;
int D[MAXN], d;

struct mal
{
	int mn, gd;
} T[MAXN*4], pl;

int gcd(int x,int y)
{
	if(!y)	return x;
	return gcd(y, x%y);
}

void add(int x,int y,int l,int r,int node)
{
	if(l == r)	{T[node].gd = T[node].mn = y; return;}
	
	if(x <= (l+r)/2)	add(x, y, l, (l+r)/2, node*2);
	else 	add(x, y, (l+r)/2+1, r, node*2+1);
	
	if(T[node*2+1].gd == 0)	T[node].gd = T[node*2].gd;
	else T[node].gd = gcd(T[node*2].gd, T[node*2+1].gd);
	T[node].mn = mi(T[node*2].mn, T[node*2+1].mn);
}

mal query(int x,int y,int l,int r,int node)
{
	if(x <= l  &&  r <= y)	return T[node];
	
	if(x > r  ||  y < l)	return pl;
	
	mal a = query(x, y, l, (l+r)/2, node*2);
	mal b = query(x, y, (l+r)/2+1, r, node*2+1);
	
	if(!a.gd)	a.gd = b.gd;
	else if(b.gd)	a.gd = gcd(a.gd, b.gd);
	a.mn = mi(a.mn, b.mn);
	
	return a;
}

int main()
{
	int po[30];
	
	po[0] = 1;
	
	for(int h=1; h<20; h++)	po[h] = po[h-1]*2;
	
	int k = (MAXN-3)*4;
	
	for(int h=0; h<k; h++)	T[h].mn = INF;
	
	pl.mn = INF;
	
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
	{int a;
		scanf("%d",&a);
		add(h, a, 1, n, 1);
	}
	
	///mal po = query(5, 5, 1, n, 1);
	///printf("__%d  %d\n",po.mn,po.gd);
	
	for(int h=18; h>-1; h--)
	{
		p = 0;
		k1 = ans+po[h];
		l = n-k1+2;
		for(int j=1; j<l; j++)
		{
			mal k = query(j, j+k1-1, 1, n, 1);
			
			if(k.mn == k.gd)	{p = 1;break;}
		}
		
		if(p)	ans += po[h];
	}
	
	for(int h=1; h<n-ans+2; h++)
	{
		mal k = query(h, h+ans-1, 1, n, 1);
		if(k.mn == k.gd)	D[d++] = h;
	}
	
	printf("%d %d\n",d,ans-1);
	
	for(int h=0; h<d; h++)	printf("%d ",D[h]);
}
