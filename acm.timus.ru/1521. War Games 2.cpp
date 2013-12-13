# include <stdio.h>

struct mal
{
	int ch;
	bool yes;
} T[1<<19];

int n, nr, k, m, a = 1;

int p[30];

void build(int l,int r,int node)
{
	T[node].yes = n >= (l+r)/2;
	
	if(l == r)	{T[node].ch = T[node].yes; return;}
	
	build(l, (l+r)/2-1, node*2);
	build((l+r)/2+1, r, node*2+1);
	
	T[node].ch += T[node*2].ch + T[node*2+1].ch + T[node].yes;
}

int find(int x,int l,int r,int node)
{
	if(l == r)	return l;
	
	if(T[node].yes  &&  T[node*2].ch == x-1)	return (l+r)/2;
	
	if(T[node*2].ch < x)	return find(x - T[node].yes - T[node*2].ch, (l+r)/2+1, r, node*2+1);
	
	return find(x, l, (l+r)/2-1, node*2);
}

void del(int x,int l,int r,int node)
{
	if(x == (l+r)/2)	{k = T[node].yes; T[node].ch -= k; T[node].yes = 0; return ;}
	
	if(x < (l+r)/2)	del(x, l, (l+r)/2-1, node*2);
	else 	del(x, (l+r)/2+1, r, node*2+1);
	
	T[node].ch -= k;
}

int main()
{
	p[0] = 1;
	
	for(int h=1; h<20; h++)	p[h] = p[h-1]*2;
	
	scanf("%d %d",&n,&m);
	
	for(int h=1; h<30; h++)
		if(n < p[h])
		{
			nr = p[h]-1;
			break;
		}
	
	build(1, nr, 1);
	
	for(int h=0; h<n; h++)
	{
		a += m - 1;
		
		a %= T[1].ch;
		
		if(!a)	a += T[1].ch;
		
		int tmp = find(a, 1, nr, 1);
		
		printf("%d\n",tmp);
		
		del(tmp, 1, nr, 1);
	}
}
