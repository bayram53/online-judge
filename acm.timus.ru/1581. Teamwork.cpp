# include <stdio.h>

int n,san=0;
int t[1009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	scanf("%d",&t[h]);
	
	san=1;
	int g=t[0];
	for(int h=1; h<n; h++)
	{
		if(g!=t[h]){ printf("%d %d ",san,g); san=1; g=t[h]; }
		else san++;
	}
	printf("%d %d",san,g); 
	return 0;
}
