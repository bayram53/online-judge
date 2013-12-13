#include <stdio.h>
#include <stdlib.h>

struct students
{
int a,b;
};

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int ans[100009],p=0;
bool vis1[100009];
bool vis[100009];
students t[100009];
students son[100009];
int g,n,m,c=0,q;
int parent[2][200090];
int add[100009];

int query(int *d,int x)
{
	if(d[x]==x)
		return x;
		
	return d[x]=query(d,d[x]);
}

void birlesdir(int x,int y)
{
	int k=query(parent[0],x);
	int l=query(parent[0],y);
	
	if(k!=l)
	{
		if(parent[1][k]>parent[1][l])
		{
			parent[1][k]+=parent[1][l];
			parent[0][l]=parent[0][k];
			
		}
		
		else
		{
			parent[1][l]+=parent[1][k];
			parent[0][k]=parent[0][l];
		}
		
		p--;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	p=n;
	for(int h=0; h<n; h++)
	{
		parent[0][h]=h;
		parent[1][h]=1;
	}
	
	for(int h=0; h<m; h++)
		scanf("%d %d",&t[h].a,&t[h].b);

	scanf("%d",&q);
	
	for(int h=0; h<q; h++)
	{
		scanf("%d",&add[h]);
		vis[add[h]-1]=1;
	}
	
	for(int h=0; h<m; h++)
		if(vis[h]==0)
			birlesdir(t[h].a-1,t[h].b-1);
	
	for(int h=q-1; h>=0; h--)
	{
		ans[h]=p;
		
		birlesdir(t[add[h]-1].a-1,t[add[h]-1].b-1);
	}
	
	for(int h1=0; h1<q; h1++)
		printf("%d ",ans[h1]);
}

