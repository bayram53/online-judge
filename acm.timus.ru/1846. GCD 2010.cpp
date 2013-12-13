# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define INF INT_MAX

using namespace std;

int gcd(int n,int m)
{
	if(m == 0)
		return n;
	
	return gcd(m,n%m);
}

struct mal
{
	int a,b,d;
	char c;
};

int n;
mal t[100009];
int k[100009];
int p[100009];
int d[100009];
int r1[400009];

void add(int x,int l,int r,int b)
{
	r1[b] = gcd(r1[b] , p[x]);

	if(l == r)
		return ;
		
	if(x <= (l + r)/2)
		add(x, l , (r+l)/2 , b*2);
	
	else
		add(x, (l+r)/2+1 , r , b*2+1);
}

int sow(int x,int l,int r,int b)
{
	if(l == r)
		return b;
		
	else if(x <= (l+r)/2)
		return sow(x , l , (l+r)/2 , b*2);
	else
		return sow(x, (l+r)/2+1 , r , b*2+1);
}

void del(int x)
{
	r1[x]=gcd(r1[x*2],r1[x*2+1]);
	
	if(x != 1)
		return del(x/2);
	
}

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return m.a-n.a;
}

int so1(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return m.b-n.b;
}

int main()
{
	scanf("%d\n",&n);
	
	t[0].a=-1;
	
	for(int h=1; h<=n; h++)
	{
		scanf("%c %d",&t[h].c,&t[h].a);
		
		if(h != n)
			scanf("\n");
		
		t[h].b=h;
		
	}
	
	qsort(t,n+1,sizeof(mal),so);
	
	for(int h=1; h<=n; h++)
	{
		p[h]=t[h].a;
		
		if(t[h-1].a == t[h].a)
			t[h].d=t[h-1].d;
		else
			t[h].d=h;
	}
	
	qsort(t,n+1,sizeof(mal),so1);
	
	for(int h=1; h<=n; h++)
	{//printf("%d\n",sow(t[h].d,1,100000,1));
		if(t[h].c == '+')
		{
			if(k[t[h].d] == 0)
				add(t[h].d,1,n,1);
			k[t[h].d]++;
		}
		else
		{
			if(k[t[h].d]==1)
			{
				int ke=sow(t[h].d,1,n,1);
				r1[ke]=0;
				del(ke/2);
			}
			k[t[h].d]--;
		}
		
		if(r1[1]!=0)
			printf("%d\n",r1[1]);
		
		else
			printf("1\n");
	}
}
