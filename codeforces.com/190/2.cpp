# include <stdio.h>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

int r,g,b,ans,a1,b1;

int main()
{
	scanf("%d %d %d",&r,&g,&b);
	
	a1 = (r/3)+(b/3)+(g/3)+mi(mi(r%3 , b%3) , g%3);
	
	if(r > 3)
	{
		if(r%3 == 0)	b1 += r/3-1 , r = 3;
		else 	b1 += r/3,r%=3;
	}
	
	if(g > 3)
	{
		if(g%3 == 0)	b1 += g/3-1 , g = 3;
		else 	b1 += g/3,g%=3;
	}
	
	if(b > 3)
	{
		if(b%3 == 0)	b1 += b/3-1 , b = 3;
		else 	b1 += b/3,b%=3;
	}
	
	int k = mi(r,mi(b,g));
	
	r -= k;
	g -= k;
	b -= k;
	
	b1 += r/3 + b/3 + g/3 + k;
	
	printf("%d\n",ma(a1,b1));
}
