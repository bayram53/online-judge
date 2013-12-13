# include <stdio.h>
# define mod 1000000007

int n,a,m;
int d[1009];
int k[1009];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
		scanf("%d",&a) , d[a] = -1;
	
	for(int h=1; h<=n; h++)
	{
		if(d[h] == -1  &&  d[h-1])
		{
			
			
		}
		
		if(d[h] != -1  &&  d[h-1] != -1)
			d[h] += d[h-1]+1;
	}
			
			
			
}
