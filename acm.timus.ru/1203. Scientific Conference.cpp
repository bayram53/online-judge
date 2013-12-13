# include <stdio.h>
# include <algorithm>
# include <stdlib.h>

using namespace std;

struct mal
{
	int a,b; 
};

int n,q,ans=-1;
mal t[100009];
int b[524288*2];

void add(int x,int y,int l,int r,int z)
{
	b[z]=max(b[z],y);
	
	if(l==r)
		return ;
		
	else if(x<=(l+r)/2)
		add(x,y,l,(r+l)/2,z*2);
	
	else
		add(x,y,(l+r)/2+1,r,z*2+1);
}

void query(int x,int l,int r,int z)
{
	if(l==r)
		q=max(b[z],q);
	
	else if(x<=(l+r)/2)
		query(x,l,(l+r)/2,z*2);
	
	else
		q=max(q,b[z*2]),query(x,(l+r)/2+1,r,z*2+1);
	
}

int so(void const *x,void  const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.b==n.b)
		return m.a-n.a;
		
	else
		return m.b-n.b;
	
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&t[h].a,&t[h].b);
	
	qsort(t,n,sizeof(mal),so);
	
	for(int h=0; h<n; h++)
	{
		q=-1;
		
		query(t[h].a-1,1,524288,1);
		
		if(ans<1+q)
			ans=q+1;
		
		add(t[h].b,q+1,1,524288,1);
	}
	
	printf("%d",ans);
}
