# include <stdio.h>

int n,x;

int d[1009],c,a,b,k;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&x);
		
		if(x < 0  &&  a == 0)	a = x;
		else if(x > 0  &&  b == 0)	b = x;
		else 	d[c++] = x;
	}
	
	printf("1 %d\n",a);
	k = c;
	if(b == 0)
	{printf("2 ");
		for(int h=0; h<c; h++)
			if(d[h]  &&  b < 2)
				printf("%d ",d[h]) , b++ , d[h] = 10001;
		c-=2;
	}
	
	else printf("1 %d",b);
	printf("\n%d ",c);
	
	
	for(int h=0; h<k; h++)if(d[h] != 10001)	printf("%d ",d[h]);
}
