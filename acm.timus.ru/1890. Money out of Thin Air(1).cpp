# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <vector>

# define MAXN 50009
# define ma(x,y) (x>y ? x : y)
# define mi(x,y) (x<y ? x : y)

using namespace std;

typedef long long lld;

vector <int> G[MAXN];

int n, q, x, nr = 224, ti;

lld sa[MAXN], s[MAXN];

struct mal1
{
	lld val, tmp;
} sq[300];

struct mal2
{
	int in, out;
} pos[MAXN];

void dfs(int cur)
{
	pos[cur].in = ++ti;
	for(int h=0; h<(int)G[cur].size(); h++)
		dfs(G[cur][h]);
	pos[cur].out = ti;
}

void add(int x,int y,lld z)
{
	for(int h=0; h<300; h++)
	{
		int a = h*nr;
		int b = (h+1)*nr-1;
		
		if(y < a)	break;
		
		if(x > b)	continue;
		
		if(x <= a  &&  y >= b)	sq[h].tmp += z, sq[h].val += (lld)(b-a+1)*z;
		
		else 
		{
			int a1 = ma(x, a);
			int b1 = mi(y, b);
			
			sq[h].val += (lld)(b1-a1+1)*z;
			
			for(int j=a1; j<=b1; j++)	sa[j] += z;
		}
	}
	
}

lld query(int x,int y)
{
	lld ret = 0;
	
	for(int h=0; h<300; h++)
	{
		int a = h*nr;
		int b = (h+1)*nr-1;
		
		if(y < a)	break;
		
		if(x > b)	continue;
		
		if(x <= a  &&  y >= b)	ret += sq[h].val;
		
		else 
		{
			int a1 = ma(x, a);
			int b1 = mi(y, b);
			
			ret += lld(b1-a1+1)*sq[h].tmp;
			
			for(int j=a1; j<=b1; j++)	ret += sa[j];
		}
	}
	
	return ret;
}

int main()
{
	scanf("%d %d %lld",&n,&q,&s[0]);
	
	for(int h=1; h<n; h++)
	{
		scanf("%d %lld",&x,&s[h]);
		G[x].push_back(h);
	}
	
	dfs(0);
	
	for(int h=0; h<n; h++)	add(pos[h].in, pos[h].in, s[h]);
	
	while(q--)
	{
		char type[19];
		lld y, z;
		
		scanf("%s %d %lld %lld",type,&x,&y,&z);
		
		int f1 = pos[x].in;
		int f2 = pos[x].out;
		lld f = (lld)(f2-f1+1);
		
		if(type[0] == 'e'  &&  query(f1, f1) < y)	add(f1, f1, z);
		
		if(type[0] == 'd'  &&  query(f1, f2)/f < y)	add(f1, f2, z);
	}
	
	for(int h=0; h<n; h++)	printf("%lld\n",query(pos[h].in, pos[h].in));
	
	//printf("__%lld",query(1,n));
}
