# include <stdio.h>

int n,k;
int a,b;
int x,y;

int main()
{
	scanf("%d %d",&n,&k);
	
	a=k-2;
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&x,&y);
		
		a += x - 2;
		b += y;
	}
	
	if(b > a)
		printf("Big Bang!");
	else
		printf("%d",a-b);
}
