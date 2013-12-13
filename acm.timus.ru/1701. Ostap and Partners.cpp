# include <stdio.h>
# include <string.h>

# define MAXN 50009
# define mi(x,y) (x<y ? x : y)

struct mal
{
	int par, ch, val, up, mn;
} D[MAXN];

int n, m, i, j, d, tmp;

void sw(int &x,int &y)
{
	tmp = x;
	x = y;
	y = tmp;
}

int find_set(int x)
{
	bool p = 0;
	
	if(D[D[x].par].par != D[x].par)	p = 1;
	
	if(x == D[x].par)	return x;
	
	find_set(D[x].par);
	
	if(p)	D[x].val += D[D[x].par].up, D[x].up += D[D[x].par].up;
	
	return D[x].par = D[D[x].par].par;
}

void un_sets()
{
	int a = find_set(i);
	int b = find_set(j);
	
	if(D[a].ch > D[b].ch)	sw(a, b), sw(i, j), d *= -1;
	
	D[a].par = b;
	D[b].ch += D[a].ch;
	D[a].up = D[j].val - (D[i].val - d);
	D[a].val += D[a].up;
	D[b].mn = mi(D[b].mn, D[a].mn+D[a].up);
}

int main()
{
	scanf("%d %d",&m,&n);
	
	for(int h=0; h<m; h++)	D[h].par = h, D[h].ch = 1;
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d %d",&i,&j,&d);
		
		if(find_set(i) != find_set(j))
			un_sets();
		
		else
		{
			find_set(i);
			find_set(j);
			
			if(D[i].val - D[j].val  !=  d)
			{
				printf("Impossible after %d statements",h+1);
				return 0;
			}
		}
		
		find_set(0);
		
		if(D[0].val > D[D[0].par].mn)
		{
			printf("Impossible after %d statements",h+1);
			return 0;
		}
	}
	
	printf("Possible\n");
	
	for(int h=0; h<m; h++)	find_set(h);
	
	for(int h=0; h<m; h++)	printf("%d\n",D[h].val-D[D[h].par].mn);
}
