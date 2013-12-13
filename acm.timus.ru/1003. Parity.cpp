# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <algorithm>

using namespace std;

int n,m;

struct mal1
{
	int a,b,c;
};

struct mal2
{
	int par,siz;
};

mal2 f[10009];

mal1 d[5009];

char s[109];

int e[10009],e1,e2;

int b_s(int x,int l,int r)
{
	if(r-l < 2)
	{
		if(e[l] == x)	return l;
		return r;
	}
	
	if(e[(l+r)/2] < x)	return b_s(x,(l+r)/2,r);
	
	return b_s(x,l,(l+r)/2);
}

int find_set(int x)
{
	if(x != f[x].par)	return f[x].par = find_set(f[x].par);
	return x;
}

void union_sets(int x,int y)
{
	int a = find_set(x);
	int b = find_set(y);
	
	if(a != b)
	{
		if(f[a].siz < f[b].siz)	f[b].siz += f[a].siz , f[a].par = b;
		else 	f[a].siz += f[b].siz , f[b].par = a;
	}
}

int main()
{
	while(1)
	{
		gets(s);
		
		m = strlen(s);
		
		n = 0;
		
		if(m == 0)	return 0;
		
		for(int h=0; h<m; h++)
		{
			if(!isdigit(s[h]))	return 0;
			n *= 10;
			n += s[h]-48;
		}
		
		scanf("%d",&m);
		
		e2 = e1 = 0;
		
		int w = 0;
		
		for(int h=0; h<m; h++)
		{
			scanf("%d %d %s",&d[h].a,&d[h].b,s);
			d[h].a--;
			
			if(d[h].b > n)	printf("%d\n",h) , w = 1;
			
			e[e2++] = d[h].a;
			e[e2++] = d[h].b;
			
			d[h].c = 0;
			
			if(s[0] == 'o')	d[h].c = 1;
		}
		
		if(w)	continue;
		
		sort(e , e+e2);
		
		for(int h=1; h<e2; h++)
			if(e[e1] != e[h])	e[++e1] = e[h];
		
		e1++;
		
		for(int h=0; h<e1*2; h++)	f[h].par = h;
		
		for(int h=0; h<m; h++)
		{
			int a = b_s(d[h].a,0,e1-1);
			int b = b_s(d[h].b,0,e1-1);
			
			if(d[h].c)	union_sets(a,b+e1) , union_sets(a+e1,b);
			else 	union_sets(a,b) , union_sets(a+e1,b+e1);
			
			if(find_set(a) == find_set(a+e1)  ||  find_set(b) == find_set(b+e1))	{printf("%d\n",h); w = 1; break;}
		}
		
		if(!w)	printf("%d\n",m);
		scanf("\n");
	}
	
}
