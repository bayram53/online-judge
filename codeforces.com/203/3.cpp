# include <stdio.h>
# include <algorithm>

# define MAXN 100009

using namespace std;

struct mal
{
	int x, y;
} P[MAXN], Z[MAXN], k1;

int p, a, n, pos, k, ans;

char dir;

struct mal1
{
	int x, k;
	char dir;
} pr[MAXN*10];

int cmp1(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.y == n.y)return m.x - n.x;
	return m.y - n.y;
}

int cmp2(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return m.x - n.x;
}

void tap(int x,int y,int cor)
{
	k = abs(y-x);
	
	if(x < y  &&  cor == 1)		dir = 'R';
	if(x > y  &&  cor == 1)		dir = 'L';
	
	if(x < y  &&  cor == 2)		dir = 'U';
	if(x > y  &&  cor == 2)		dir = 'D';
}

void op(mal po)
{
	if(po.x)	tap(0, po.x, 1), pr[ans].x = 1, pr[ans].k = k, pr[ans++].dir = dir;
	if(po.y)	tap(0, po.y, 2), pr[ans].x = 1, pr[ans].k = k, pr[ans++].dir = dir;
	pr[ans++].x = 2;
	
	if(po.y)	tap(po.y, 0, 2), pr[ans].x = 1, pr[ans].k = k, pr[ans++].dir = dir;
	if(po.x)	tap(po.x, 0, 1), pr[ans].x = 1, pr[ans].k = k, pr[ans++].dir = dir;
	pr[ans++].x = 3;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&k1.x,&k1.y);
		
		if(k1.y)	P[p++] = k1;
		else 	Z[a++] = k1;
	}
	
	qsort(P, p, sizeof(mal), cmp1);
	qsort(Z, a, sizeof(mal), cmp2);
	
	for(int h=1; h<a; h++)
		if(Z[h-1].x < 0  &&   Z[h].x > 0)	pos = h;
	
	if(!pos  &&  a  &&  Z[a-1].x < 0)	pos = a;
	
	for(int h=pos-1; h>-1; h--)	op(Z[h]);
	
	for(int h=pos; h<a; h++)	op(Z[h]);
	
	
	pos = 0;
	for(int h=1; h<p; h++)
		if(P[h-1].y < 0  &&   P[h].y > 0)	pos = h;
	
	if(!pos  &&  p  &&  P[p-1].y < 0)	pos = p;
	
	for(int h=pos-1; h>-1; h--)	op(P[h]);
	
	for(int h=pos; h<p; h++)	op(P[h]);
	
	
	printf("%d\n",ans);
	
	for(int h=0; h<ans; h++)
	{
		printf("%d",pr[h].x);
		
		if(pr[h].x == 1)	printf(" %d %c",pr[h].k,pr[h].dir);
		
		printf("\n");
	}
}
