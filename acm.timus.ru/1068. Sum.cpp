# include <stdio.h>
# include <stdlib.h>

int n,m=0,k;

int main()
{
	scanf("%d",&n);
	if(n==0) {printf("1"); return 0;}
	k=abs(n);
	for(int h=1; h<=k; h++)
	m+=h;
	if(n<0) printf("%d",-1*m+1);
	else printf("%d",m);
}
