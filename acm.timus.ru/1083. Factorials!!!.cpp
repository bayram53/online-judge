# include <stdio.h>
# include <string.h>

int n,san;
char c[100];

int main()
{
	scanf("%d %s",&n,c);
	san=strlen(c);
	if(san>=n) { printf("%d",n); return 0; }
	
	for(int h=n-san; h>1; h-=san)
	n*=h;
	
	printf("%d",n);
}
