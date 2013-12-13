# include <stdio.h>

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	if((n*m)%2==0) printf("[:=[first]");
	else printf("[second]=:]");
}
