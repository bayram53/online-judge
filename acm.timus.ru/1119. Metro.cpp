# include <stdio.h>
# include <stdlib.h>

struct mal
{
	int a,b;
};

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
	
	else
		return m.a-n.a;
}

int n,m,k,o,ans=0;
float p=141.421356237;
mal t[109];
int d[109];

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
	for(int h=0; h<k; h++)
		scanf("%d %d",&t[h].a,&t[h].b);
	
	qsort(t,k,sizeof(mal),so);
	
	for(int h=k-1; h>-1; h--)
	{
		o=0;
		
		for(int j=h+1; j<k; j++)
		if(o<d[j] && t[h].a<t[j].a && t[h].b<t[j].b)
			o=d[j];
		
		d[h]=o+1;
		
		if(ans<o+1)
			ans=o+1;
	}
	
	p=p*float(ans)+100.0*float(n-ans)+100.0*float(m-ans);
	
	ans=int(p);
	
	if(p>=float(ans)+0.5)
		ans++;
		
	printf("%d",ans);
}
