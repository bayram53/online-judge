# include <stdio.h>

int a,b,c,d;

int main()
{
	scanf("%d %d",&a,&b);
	
	for(int h=0; h<10; h++)
	{
		scanf("%d",&c);
		d+=c;
	}
	
	if(b-(d*20)<a)
		printf("Dirty debug :(");
		
	else
		printf("No chance.");
}
