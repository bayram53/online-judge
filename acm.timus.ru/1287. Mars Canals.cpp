# include <stdio.h>
# define ma(x,y) (x>y ? x : y)
# define mi(x,y) (x<y ? x : y)

int n,a,b;

char s[2009][2009];

void tap(int x,int y,int x1,int y1)
{
	int m=1;
	char c=s[x][y];
	
	while(1)
	{
		x += x1;
		y += y1;
		
		if(mi(x,y) < 0  ||  ma(x,y) > n-1)	break;
		
		if(c != s[x][y])
		{
			if(c == 'S') a = ma(m,a);
			else if(c == 's')	b = ma(m,b);
			c = s[x][y];
			m = 1;
		}
		
		else m++;
	}
	
	if(c == 'S') a = ma(m,a);
	else if(c == 's') 	b = ma(m,b);
	
	//printf("%c __ %d\n\n",c,m);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%s",s[h]);
	
	for(int h=0; h<n; h++)
	{
		tap(0,h,1,1);
		tap(h,0,1,1);
		tap(h,n-1,1,-1);
		tap(n-1,h,-1,1);
		tap(0,h,1,0);
		tap(h,0,0,1);
	}
	
	//printf("%d %d\n",a,b);
	
	if(a > b)	printf("S");
	else if(b > a)	printf("s");
	else printf("?");
	printf("\n%d",ma(a,b));
}
