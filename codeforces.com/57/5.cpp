# include <stdio.h>
# include <algorithm>

# define MAXN 1000009
# define ma(x,y) (x>y ? x : y)
# define mi(x,y) (x<y ? x : y)

using namespace std;

typedef long long llint;

struct mal
{
	int id,val;
};

int n;

llint bi1[MAXN] , bi2[MAXN] , ans , p;

int D[MAXN] , S[MAXN];

int b_s(int x,int l,int r)
{
	if(r-l < 2)
	{
		if(S[l] == x)	return l;
		return r;
	}
	
	if(S[(l+r)/2] < x)	return b_s(x,(l+r)/2,r);
	
	return b_s(x,l,(l+r)/2);
}

void add(int x,llint y,llint *E)
{
	for(int h=x; h<=n; h += h & -h)
		E[h] += y;
}

llint query(int x,llint *E)
{
	llint sum = 0;
	
	for(int h=x; h>0; h -= h & -h)
		sum += E[h];
	
	return sum;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&S[h+1]) , D[h] = S[h+1];
	
	sort(S , S+(n+1));
	
	for(int h=n-1; h>-1; h--)
	{
		int k = b_s(D[h],1,n);
		llint r = query(k,bi1);
		add(k,1,bi1);
		ans += query(k,bi2);
		add(k,r,bi2);
		p += r;
	}
	
	printf("%I64d",ans);
}
