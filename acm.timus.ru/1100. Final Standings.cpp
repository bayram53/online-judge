# include <stdio.h>
# define max 150009

int res[109][max];
int n,a,b;

int main()
{
	for(int h=0; h<=100; h++)
		res[h][max-1]=0;
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		res[b][res[b][max-1]++]=a;
	}
	
	for(int h=100; h>=0; h--)
		for(int j=0; j<res[h][max-1]; j++)
			printf("%d %d\n",res[h][j],h);
	
	
}
