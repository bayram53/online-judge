# include <stdio.h>
# include <limits.h>
# define inf LLONG_MAX-10000000
# define mi(x,y) (x<y ? x : y)
# include <stdlib.h>

struct mal
{
	long long a,b,c;
	char d;
};

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.b==n.b)
		return m.a-n.a;
		
	else
		return m.b-n.b;
}

long long t1[10009][2];
int n,m;
mal t[10009];
char c[19];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=2; h<=n+1; h++)
		t1[h][0]=inf,t1[h][1]=inf;
	
	for(int h=0; h<m; h++)
	{
		scanf("%lld %lld %lld %s",&t[h].a,&t[h].b,&t[h].c,c);
		t[h].d=c[0];
	}
	
	qsort(t,m,sizeof(mal),so);
	
	for(int h=0; h<m; h++)
	{
		if(t[h].d=='L')
			t1[t[h].b][1]=mi(t1[t[h].a][1]+t[h].c,t1[t[h].b][1]);
		
		else
			t1[t[h].b][0]=mi(mi(t1[t[h].a][1],t1[t[h].a][0])+t[h].c,t1[t[h].b][0]);
			
		if(t[h].d=='C' && t1[t[h].a][1]!=inf)
			t1[t[h].b][1]=mi(t1[t[h].a][1]+t[h].c,t1[t[h].b][1]);
			
	}
	
	if(inf==t1[n][0] && t1[n][1]==inf)
		printf("Offline");
		
	else
		printf("Online\n%lld",mi(t1[n][1],t1[n][0]));
}
