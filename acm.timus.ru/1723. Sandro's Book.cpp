# include <stdio.h>
# include <string.h>

char n[55];
int  m,ma=-1,l;
int c[30];

int main()
{
	scanf("%s",n);
	
	m=strlen(n);
	
	for(int h=0; h<m; h++)
		c[n[h]-96]++;
	
	
	for(int h=0; h<28; h++)
	if(ma<c[h])
	{
		ma=c[h];
		l=h;
	}
	
	l+=96;
	
	printf("%c",l);
}
