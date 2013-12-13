# include <stdio.h>
# include <string.h>
# define inf 999999
# define mi(x,y) (x<y ? x : y);

int n,m=1;
int t[29];
int cost[2097152];
int vis[2097152];
int b[2097152];

struct mal
{
	int a,b;
};

mal tap(int x,int y)
{
	int r[29],p=n-1;
	mal l;
	l.b=0;
	l.a=cost[x];
	
	memset(r,0,sizeof(r));
	
	while(x!=0)
	{
		r[p--]=x%2;
		x/=2;
	}
	
	int a=y-1,b=y+1;
	
	if(a==-1)
		a=n-1;
		
	if(b==n)
		b=0;
	
	r[y]=0;
	r[a]=0;
	r[b]=0;
	
	int e=1;
	
	for(int h=n-1; h>-1; h--)
	{
		l.b+=r[h]*e;
		e*=2;
		
		if(r[h]==1)
			l.a+=t[h];
	}
	
	return l;
}

void tapmak()
{
	int x=0,y=1;
	vis[m]=1;
	b[x]=m;
	
	while(x<y)
	{
		for(int h=0; h<n; h++)
		{
			mal a1=tap(b[x],h);
			
			if(vis[a1.b]==0)
				b[y++]=a1.b;
			
			vis[a1.b]=1;
			cost[a1.b]=mi(a1.a,cost[a1.b]);
		}
		
		x++;
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	m=m<<n;
	m--;
	
	for(int h=0; h<m; h++)	
		cost[h]=inf;
	
	tapmak();
	
	printf("%d",cost[0]);
}
