# include <stdio.h>

# define MAXN 100009

int n, k, nr = 316, m = 1;

int sq[400], v[MAXN];

void upd(int x,int y)
{
	v[x] += y;
	sq[x/nr] += y;
}

int query(int x)
{
	int ret = 0, p = -1;
	
	for(int h=0; h<318; h++)
	{
		if(ret + sq[h] < x)	ret += sq[h];
		
		else
		{
			for(int j=h*nr; j<(h+1)*nr; j++)
			{
				ret += v[j];
				if(v[j]  &&  ret == x)	p = j;
			}
			
			break;
		}
	}
	
	return p;
}

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)	upd(h+1, 1);
	
	for(int h=0; h<n; h++)
	{
		m += k-1;
		
		m %= (n-h);
		
		if(!m)	m = n-h;
		
		int l = query(m);
		
		printf("%d ",l);
		
		upd(l, -1);
	}
}
