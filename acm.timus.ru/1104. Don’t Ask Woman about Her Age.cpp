# include <stdio.h>
# include <ctype.h>
# include <string.h>

int n,a=0;
char c[1000009];

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=2; h<=36; h++)
	{
		a=0;
		
		for(int j=0; j<n; j++)
		{
			if((isalpha(c[j])!=0 && c[j]-55>=h) || (isdigit(c[j])!=0 && h<=c[j]-48))
				{a=-1;break;}
			
			if(isalpha(c[j]))
				a+=c[j]-55;
				
			else
				a+=c[j]-48;
				
			a%=(h-1);
		}
		
		if(a==0)
		{
			printf("%d",h);
			return 0;
		}
		
	}
	
	printf("No solution.");
}
