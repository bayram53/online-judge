# include <stdio.h>
# include <algorithm>
# define inf 3000009
# define mi(x,y) (x<y ? x : y)

using namespace std;

struct mal
{
	int a,b,c;
};
int v[109][2];
int bfs[109],s1=0,s2=1;
int n,q,a,b,c,toplam;
mal t[109][2];
int l[109][109];
int k[109][109];
int p[109];
mal g[109];
bool vis[109][109];

int gozle(int x)
{
	if(t[x][0].a!=0)
	{
		v[x][0]=gozle(t[x][0].a)+gozle(t[x][1].a);
		v[x][1]=v[t[x][0].a][1]+v[t[x][1].a][1]+2;
		return v[x][0]+l[p[x]][x];
	}
	
	else
		return l[p[x]][x];
}

int tap(int x,int y)
{
	if(vis[x][y]==1)
		return k[x][y];
	
	vis[x][y]=1;
	
	if(t[x][0].a==0 && y>1)
		return k[x][y]=inf;
	
	if(y==0)
		return k[x][y]=0;
	
	if(y==v[x][1]+1)
		return k[x][y]=v[x][0]+l[p[x]][x];
	
	if(y==v[x][1])
		return k[x][y]=v[x][0];
	
	for(int h=0; h<=y; h++)
		k[x][y]=mi(k[x][y],tap(t[x][0].a,h)+tap(t[x][1].a,y-h));
	
	return k[x][y];
}

int main()
{
	for(int h=0; h<109; h++)
		for(int j=0; j<109; j++)
			k[h][j]=inf;
	
	for(int h=0; h<108; h++)
		t[h][0].a=0,t[h][1].a=0;
	
	scanf("%d %d",&n,&q);
	
	q=n-q-1;
	
	for(int h=0; h<n-1; h++)
		scanf("%d %d %d",&g[h].a,&g[h].b,&g[h].c);
	
	bfs[0]=1;
	
	while(s2>s1)
	{
		for(int h=0; h<n-1; h++)
		{
			if(g[h].b==bfs[s1] && p[bfs[s1]]!=g[h].a)
			{
				bfs[s2++]=g[h].a;
				p[g[h].a]=g[h].b;
				swap(g[h].a,g[h].b);
			}
			
			else if(g[h].a==bfs[s1])
				p[g[h].b]=g[h].a,bfs[s2++]=g[h].b;
		}
			
		s1++;
	}
	
	for(int h=0; h<n-1; h++)
	{
		l[g[h].a][g[h].b]=g[h].c;
		if(t[g[h].a][0].a==0)
			t[g[h].a][0].a=g[h].b,t[g[h].a][0].b=g[h].c;
			
		else
			t[g[h].a][1].a=g[h].b,t[g[h].a][1].b=g[h].c;
	}
	
	toplam=gozle(1);
	
	printf("%d",toplam-tap(1,q));
}
