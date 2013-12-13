# include <stdio.h>

int n, k, ans;

int main()
{
	scanf("%d %d",&n,&k);
	
	if(!k)
	{
		for(int h=1; h<=2*n; h++)	printf("%d ",h);
		return 0;
	}
	
	printf("1 %d ",1+k);
	
	for(int h=2*n; h>1; h--)
		if(1+k != h)
			printf("%d ",h);
}
