# include <stdio.h>
# include <string.h>

char c[109];
int n;
int t[109];

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=0; h<n; h++)
	t[h]=c[h]-97;
	
	for(int h=1; h<n; h++)
	if(t[h]<t[h-1])
	while(t[h]<t[h-1])
	{
		t[h]+=26;
	}
	
	for(int h=n-1; h>0; h--)
	t[h]-=t[h-1];
	
	t[0]-=5;
	t[0]+=26;
	t[0]%=26;
	
	for(int h=0; h<n; h++)
	printf("%c",t[h]+97);
}
