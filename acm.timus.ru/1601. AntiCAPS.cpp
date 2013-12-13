# include <stdio.h>
# include <ctype.h>

char a,c[10009];
int n;
bool son=0;

int main()
{
	while((scanf("%c",&a)!=EOF))
		c[n++]=a;
	
	for(int h=0; h<n; h++)
	{
		if(isalpha(c[h]))
		{
			if(son==1 && isupper(c[h])
			)
				printf("%c",tolower(c[h]));
			
			else if(son==0 && islower(c[h]))
				printf("%c",toupper(c[h])),son=1;
				
			else if(son==0)
				printf("%c",c[h]),son=1;
				
			else
				printf("%c",c[h]);
		}
		
		else
		{
			if(c[h]=='.' || c[h]=='?' || c[h]=='!')
				son=0;
			
			printf("%c",c[h]);
		}
	}
		
}
