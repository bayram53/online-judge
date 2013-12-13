# include <stdio.h>

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=1; h<=n; h++)
		printf("%d ",h);
	
	printf("\n");
	
	for(int h=100; h<=m*100; h+=100)
		printf("%d ",h);
}
