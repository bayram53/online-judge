# include <stdio.h>
# include <algorithm>

using namespace std;

struct mal
{
	int a,b,c;
};

int n;

mal d[509];

int dp[509][3];

int ans,a[509],p;

inline bool cmp(mal x,mal y)
{
	if(x.a == y.a)	return x.b < y.b;
	return x.a < y.a;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d %d",&d[h].a,&d[h].b) , d[h].c=h+1;
	
	sort(d , d+n , cmp);
	
	for(int h=n-1; h>-1; h--)
	{
		int k = n;
		
		for(int j=h+1; j<n; j++)	if(dp[k][0] < dp[j][0]  &&  d[h].a < d[j].a  &&  d[h].b > d[j].b)	k = j;
		
		dp[h][0] = dp[k][0]+1;
		dp[h][1] = k;
	}
	
	for(int h=0; h<n; h++)	if(dp[p][0] < dp[h][0])	p = h;
	
	while(p != n)
	{
		a[ans++] = d[p].c;
		p = dp[p][1];
	}
	
	printf("%d\n",ans);
	
	for(int h=ans-1; h>-1; h--)	printf("%d ",a[h]);
}
