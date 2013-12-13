# include <stdio.h>

char c1[4];
char c2[4];

int main()
{
	scanf("%s\n%s",c1,c2);
	
	if((c1[3]-48)%2==0 || (c2[3]-48)%2==1)
	printf("yes");
	
	else printf("no");
	
}
