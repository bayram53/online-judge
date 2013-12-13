# include <stdio.h>

int a, b, c;

int mal(int x,int y,int z)
{
	if(x+y == 0  ||  y+z == 0  ||  z+x == 0)	return 0;
	return 1;
}

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	
	for(int h=0; h<=1000000; h++)
	{
		int x = h;
		int y = a-x;
		int z = c-y;
		
		if(x + y == a  &&  y + z == c  &&  x + z == b  &&  x >= 0  &&  y >= 0  &&  z >= 0  &&  mal(x, y, z))
			{printf("%d %d %d",x,z,y); return 0;}
	}
	
	printf("Impossible");
}
