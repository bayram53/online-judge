# include <stdio.h>

int n;
int d[100009];

int main()
{
	scanf("%d",&n);
	
	if(n%2)
	{
		for(int h=0; h<n; h++)	printf("%d ",h);printf("\n");
		for(int h=0; h<n; h++)	printf("%d ",h);printf("\n");
		for(int h=0; h<n; h++)	printf("%d ",(h*2)%n);
	}
	
	else 	printf("-1");
}
