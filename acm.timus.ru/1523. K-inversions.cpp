# include <stdio.h>

# define MAXN 20009
# define mod 1000000000

typedef long long lld;

lld T[20][MAXN], ans;

int n, k, D[MAXN];

void add(int pos,int tr,lld val)
{
	for(int h=pos; h<=n; h += h & -h)
	{
		T[tr][h] += val;
		if(T[tr][h] >= mod)	T[tr][h] -= mod;
	}
}

lld find(int pos,int tr)
{
	lld re = 0;
	
	for(int j=pos-1; j>0; j -= j & -j)
	{
		re += T[tr][j];
		if(re >= mod)	re -= mod;
	}
	
	return re;
}

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)	scanf("%d",&D[h]);
	
	for(int j=n-1; j>-1; j--)
	{
		add(D[j], 0, 1);
		
		for(int i=1; i<k; i++)
			add(D[j], i, find(D[j], i-1));
	}
	
	printf("%lld",find(n+1, k-1));
}
