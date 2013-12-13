# include <stdio.h>

int n,a,b;

int f[1009][3],k,o;

bool vis[1009];

struct mal
{
	int siz,par;
};

mal d[1009];

int find_set(int x)
{
	if(d[x].par == x)	return x;
	return d[x].par = find_set(d[x].par);
}

void union_sets(int x,int y)
{
	int a = find_set(x);
	int b = find_set(y);
	
	if(a != b)
	{
		if(d[a].siz < d[b].siz)	d[b].siz += d[a].siz , d[a].par = b;
		else 	d[a].siz += d[b].siz , d[b].par = a;
	}
	
	else
	{
		f[k][0] = x;
		f[k++][1] = y;
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)	d[h].par = h;
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&a,&b);
		union_sets(a,b);
	}
	
	for(int h=1; h<=n; h++)	vis[find_set(h)] = 1;
	
	int g = -1;
	
	printf("%d\n",k);
	
	for(int h=1; h<=n; h++)
		if(vis[h])
		{
			if(g == -1)	g = h;
			else 	printf("%d %d %d %d\n",f[o][0],f[o][1],g,h) , union_sets(g,h) , g = find_set(g) , o++;
		}
}
