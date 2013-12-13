# include <stdio.h>

# define MAXN 300009

struct mal
{
	int prev, next;
} LS[MAXN];

int n,m;
int lost[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int j=1; j<=n; j++)	LS[j].prev = j-1, LS[j].next = j+1;
	
	for(int h=0; h<m; h++)
	{
		int a, b, c;
		
		scanf("%d %d %d",&a,&b,&c);
		
		int k = c;
		
		while(1)
		{
			k = LS[k].next;
			if(b < k)	break;
			lost[k] = c;
			
			LS[LS[k].prev].next = LS[k].next;
			LS[LS[k].next].prev = LS[k].prev;
		}
		
		k = c;
		
		while(1)
		{
			k = LS[k].prev;
			if(a > k)	break;
			lost[k] = c;
			LS[LS[k].prev].next = LS[k].next;
			LS[LS[k].next].prev = LS[k].prev;
		}
	}
	
	for(int h=1; h<=n; h++)	printf("%d ",lost[h]);
}
