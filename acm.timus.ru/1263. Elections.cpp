# include <stdio.h>

int n,m,d;
int vote[10009];
char shat='%';

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d",&d);
		vote[d]++;
	}
	
	printf("%.2f%c",((vote[1]*1.0)/m*1.0)*100,shat);
	
	for(int h=2; h<=n; h++)
		printf("\n%.2f%c",((vote[h]*1.0)/m*1.0)*100,shat);
	
}

