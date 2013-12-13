# include <stdio.h>
# define inf 99999999
# include <stdlib.h>
# define der 32768
# define mi(x,y) (x<y ? x : y)

struct mal
{
	int a,b;
};

mal t[100009];
int o=1;
mal ans[50009];
int m;
int n=1;
mal d;
mal a[der];
int f[der][4];

void add(int x,int y,int l,int r,int z)
{
	if(y<a[z].a)
		{a[z].a=y;a[z].b=x;}
	
	if(l==r)
		return ;
		
	else if((l+r)/2>=x)
		add(x,y,l,(l+r)/2,z*2);
	
	else
		add(x,y,(l+r)/2+1,r,z*2+1);
}

void query(int x,int l,int r,int z)
{
	if(l==r)
	{
		if(a[z].a<d.a)
			d=a[z];
		l=r;
	}
	
	else if((l+r)/2>=x)
	{if(a[z*2+1].a<d.a)d=a[z*2+1];
		query(x,l,(l+r)/2,z*2);}
	
	else
		query(x,(l+r)/2+1,r,z*2+1);
}

int so(void const *x, void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
	
	return m.a-n.a;
}

int main()
{
	for(int h=0; h<=der; h++)
		a[h].a=inf,f[h][0]=inf;
	
	f[0][0]=0;
	
	scanf("%d",&m);
	
	scanf("%d %d",&t[0].a,&t[0].b);
	
	while(t[n-1].a!=0 || t[n-1].b!=0)
	{
		scanf("%d %d",&t[n].a,&t[n].b);
		n++;
	}
	n--;
	qsort(t,n,sizeof(mal),so);
	
	for(int h=0; h<n; h++)
	if(t[h].a<=m && t[h].b>=0)
	{
		int r1=t[h].a,r2=t[h].b;
		d.a=inf;
		
		if(r1<0)
			r1=0;
		
		if(r2>m)
			r2=m;
		
		if(r1==0)
			d.a=0,d.b=0;
	
		if(r1!=0)
			query(r1,1,der/2,1);
		
		if(d.a==inf)
			continue;
		
		if(f[d.b][0]+1<f[r2][0])
		{
			 f[r2][0]=f[d.b][0]+1;
			 f[r2][1]=h;
			 f[r2][3]=d.b;
			 add(r2,f[r2][0],1,der/2,1);
		 }
	}
	
	if(f[m][0]==inf)
	{
		printf("No solution");
		return 0;
	}
	
	printf("%d\n",f[m][0]);
	
	int r1=f[m][3];
	ans[0].a=t[f[m][1]].a;
	ans[0].b=t[f[m][1]].b;
	
	while(r1!=0)
	{
		ans[o].a=t[f[r1][1]].a;
		ans[o++].b=t[f[r1][1]].b;
		r1=f[r1][3];
	}
	qsort(ans,o,sizeof(mal),so);
	for(int h=0; h<o; h++)
		printf("%d %d\n",ans[h].a,ans[h].b);
}
