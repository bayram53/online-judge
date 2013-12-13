# include <stdio.h>
# include <string.h>

int n, k, ans, a;

int main()
{
	scanf("%d %d %d",&n,&k,&a);
	
	int e = 0, h = 0;
	while(a)
	{
		h = a%10;
		a /= 10;
		e = e | 1<<h;
	}
	
	int f = (1<<(k+1))-1;
	if(e & f == f)	printf("s");
	else 	printf("no");
	
	printf("%d\n",ans);
}
