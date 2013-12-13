# include <stdio.h>
# include <stdlib.h>

struct mal
{
	int a,b;
};

int n,m,k,q,q1,ans=0,d1=0;
mal t[22009];
int b[22009];
int d[20009][2];
bool vis[20009];

int so(void const * x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
	
	else
		return m.a-n.a;
}
	
void bfs(int a)
{
	int x=1,y=0;
	vis[x]=1;
	b[0]=a;
	
	while(x>y)
	{
		for(int h=d[b[y]][0]; h<d[b[y]][1]; h++)
			if(vis[t[h].b]==0)
				vis[t[h].b]=1,b[x++]=t[h].b;
		y++;
	}
	
	/*printf("\n%d  :",a);
	for(int h=1; h<=n; h++)
		printf("%d",vis[h]);*/
}

int main()
{
	scanf("%d %d %d",&n,&k,&m);
	
	for(int h=0; h<k; h++)
		scanf("%d %d",&t[d1].a,&t[d1].b),d1++,t[d1].a=t[d1-1].b,t[d1].b=t[d1-1].a,d1++;
	
	for(int j=0; j<m; j++)
		scanf("%d %d",&q,&q1);
	
	qsort(t,k*2,sizeof(mal),so);
	
	d[t[0].a][0]=0;
	
	for(int h=1; h<k*2; h++)
		if(t[h-1].a!=t[h].a)
			d[t[h-1].a][1]=h,d[t[h].a][0]=h;
	
	d[t[k*2-1].a][1]=k*2;
		
	for(int h=1; h<=n; h++)
		if(vis[h]==0)
			bfs(h),ans++;
			
	printf("%d",ans-1);
}
