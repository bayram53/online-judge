# include <stdio.h>

int n,a;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		int x,y,s=3;
		
		scanf("%d",&a);
		printf("0 1");
		
		if(a%2==0)
			y=2,x=a/2;
		
		else
		while(1)
		{
			if(a%s==0)
				{
					x=a/s;
					y=s;
					break;
				}
				s+=2;
			}
		
		for(int j=x; j<a; j+=x)
		{
			if((j-1) % y == 0)
				printf(" %d",j);
			if((j+1) % y == 0)
				printf(" %d",j+1);
		}
		printf("\n");
	}
}
