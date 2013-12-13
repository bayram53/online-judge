# include <stdio.h>

int n,a;
bool mal[65539];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		mal[a+32768]=1;
	}
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		if(mal[10000-a+32768]==1)
		{
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
}
