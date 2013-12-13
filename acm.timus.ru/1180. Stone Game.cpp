# include <stdio.h>
# include <string.h>

int n=0,l;
char s[259];

int main()
{
	scanf("%s",s);
	
	l=strlen(s);
	
	for(int h=0; h<l; h++)
		n+=s[h]-48;
		
	if(n%3==0)
		printf("2");
		
	else
	{
		printf("1\n");
		
		if(n%3==2)
			printf("2");
			
		else
			printf("1");
	}
}
