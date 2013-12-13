# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <iostream>

# define INF LLONG_MAX/2
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

using namespace std;

typedef long long llint;

struct mal
{
	int a,b,cost;
};

int n,m,k;

mal d[100009];

inline bool cmp(mal x,mal y)
{
	return x.a <= y.a;
}

llint ra[400009],ans=INF;

void add(int x,int y,int l,int r,int a)
{
	if(ra[a] == -1  ||  ra[a] > y)	ra[a] = y;
	
	if(l == r)	return;
	
	if(x <= (l+r)/2)	add(x,y,l,(l+r)/2,a*2);
	
	else 	add(x,y,(l+r)/2+1,r,a*2+1);
}

llint query(int x,int y,int l,int r,int a)
{
	if(l == r)	return ra[a];
	
	if(x == l  &&  r == y)	return ra[a];
	
	if(y <= (l+r)/2)	return query(x,y,l,(l+r)/2,a*2);
	
	if(x > (l+r)/2)	return query(x,y,(l+r)/2+1,r,a*2+1);
	
	llint e = query(x,(l+r)/2,l,(l+r)/2,a*2);
	llint w = query((l+r)/2+1,y,(l+r)/2+1,r,a*2+1);
	
	if(e == -1)	return w;
	if(w == -1)	return e;
	return mi(e,w);
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
	for(int h=0; h<m; h++)	scanf("%d %d %d",&d[h].a,&d[h].b,&d[h].cost);
	
	sort(d , d+m , cmp);
	
	for(int h=1; h<n-k+2; h++)
	{
		memset(ra , -1 , sizeof(ra));
		
		for(int j=0; j<m; j++)
		{
			int a = ma(h,d[j].a);
			int b = mi(h+k-1,d[j].b);
			llint e = 0;
			
			if(a > h)	e = query(a-1,b,1,n,1);
			
			printf("%d    %d %d %lld\n",h,a,b,e);
			
			if(e != -1)
			{
				if(b == h+k-1)	printf("%lld\n",e+d[j].cost) , ans = mi(e+d[j].cost,ans);
				else add(a,d[j].cost+e,1,n,1) , printf("(((((((((((%d %lld\n",a,e+d[j].cost);
			}
		}
		
		printf("%lld  %d\n",ans,h);
	}
	add(6,3,1,n,1);
	printf("------------------------------(%lld) \n",query(5,8,1,n,1));
	
	if(ans == INF)	printf("-1");
	else 	cout<<ans;
}

/*
10 6 9
6 8 7
2 8 11
2 6 10
8 10 9
2 5 8
2 3 8
*/
