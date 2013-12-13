# include <stdio.h>

int n;
int d[109];
int m,x,y;

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&d[h]);
	
	scanf("%d",&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&x,&y);
		
		if(x == 1)
			d[x+1] += d[x]-y;
		else if(x == n)
			d[x-1] += y-1;
		else
			d[x-1] += y-1 , d[x+1] += d[x]-y;
		
		d[x] = 0;
	}
	
	for(int h=1; h<=n; h++)
		printf("%d\n",d[h]);
}
