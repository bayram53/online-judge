# include <stdio.h>
# include <stdlib.h>

struct mal
{
	int a,b;
	
};

int n,a,f=0;
int d[109][2];
mal t[40009];
int b[109];
int k[109];
int ans=0;
bool vis[109];

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
	
	else
		return m.a-n.a;
}

void add()
{
	int x=1,y=0;
	b[0]=1;
	vis[1]=1;
	while(x>y)
	{
		for(int h=d[b[y]][0]; h<d[b[y]][1]; h++)
		{
			if(k[t[h].b]==-1 || k[t[h].b]==(k[b[y]]+1)%2)
			{
				k[t[h].b]=(k[b[y]]+1)%2;
				
				if(vis[t[h].b]==0)
					b[x++]=t[h].b,vis[t[h].b]=1;
			}
			
			else
				ans=1;
		}
		y++;
	}
	
}

int main()
{
	for(int h=0; h<109; h++)
		k[h]=-1;
	
	k[1]=0;
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		while(1)
		{
			scanf("%d",&a);
			
			if(a==0)
				break;
			
			t[f].a=h+1;
			t[f++].b=a;
			t[f].b=h+1;
			t[f++].a=a;
		}
	}
	
	qsort(t,f,sizeof(mal),so);
	
	d[t[0].a][0]=0;
	
	for(int h=1; h<f; h++)
		if(t[h-1].a!=t[h].a)
			d[t[h-1].a][1]=h,d[t[h].a][0]=h;
			
	d[t[f-1].a][1]=f;
	
	add();
	
	if(ans==1)
	{
		printf("-1");
		return 0;
	}
	
	for(int h=1; h<=n; h++)
		printf("%d",k[h]);
}
