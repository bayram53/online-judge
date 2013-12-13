# include <stdio.h>
# include <string.h>

int a,b,n,m;
char s2[1009],s1[1009];

int main()
{
	scanf("%s %s",s1,s2);
	
	a = strlen(s1);
	b = strlen(s2);
	
	for(int h=0; h<a; h++)	n += s1[h]-48;
	for(int j=0; j<b; j++) 	m += s2[j]-48;
	
	if(n+n%2 < m)	printf("NO");
	else	printf("YES");
}
