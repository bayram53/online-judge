# include <stdio.h>
# include <cctype>
# include <string.h>

char c[300],d;
int n=0;

int main()
{
	while(scanf("%c",&d)!=EOF)
	{
		if(isalpha(d)==0)
		{
			for(int h=n-1; h>-1; h--)
				printf("%c",c[h]);
			n=0;
			printf("%c",d);
			continue;
		}
		c[n++]=d;
	}
	
	for(int h=n-1; h>-1; h--)
		printf("%c",c[h]);
}
