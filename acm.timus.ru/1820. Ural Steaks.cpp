# include <stdio.h>

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	n*=2;
	
	if(m>=n) printf("2");
 	else if(n%m==0) printf("%d",n/m);
	else printf("%d",n/m+1);
}
