# include <stdio.h>

int a,b,c,d;

int minx(int x,int y)
{
	if(x<y) return x;
	
	else return y;
	
}

int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if(a>=c)
		printf("%d",a);
		
		
		
	else
	{
		while(1)
		{
			a+=b;
			
			if(a>=c)
			{
				printf("%d",minx(a,c));
				return 0;
			}
			
			c-=d;
			
			if(a>=c)
			{
				printf("%d",a);
				return 0;
			}
		}
	}
}
