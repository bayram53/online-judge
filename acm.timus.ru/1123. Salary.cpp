# include <stdio.h>
# include <string.h>

char n[2009];
char s1[1009];
char s2[1009];
char s3[1009];
int m,l,p=0;

void tap(char x[])
{
	int k=strlen(x);
	
	for(int h=k-1; h>-1; h--)
	printf("%c",x[h]);
}

int main()
{
	scanf("%s",n);
	
	m=strlen(n);
	l=m%2;
	for(int h=0; h<m/2; h++)
		s1[h]=n[h];
	
	for(int h=m/2+l; h<m; h++)
	s2[h-m/2-l]=n[h];
	
	for(int h=m/2-1; h>-1; h--)
	s3[p++]=s1[h];
	
	if(strcmp(s3,s2)>-1)
	{
		if(m%2==0)
			printf("%s",s1);
		
		else
		printf("%s%c",s1,n[m/2]);
		
		tap(s1);
		
	}
	
	else
	{
		if(m%2==0)
		{
			for(int h=m/2-1; h>-1; h--)
			{
				if(s1[h]-48!=9)
				{
					s1[h]++;
					break;
				}
				
				s1[h]='0';
			}
			
			printf("%s",s1);
			tap(s1);
		}
		
		else
		{
			if(n[m/2]=='9')
			{
				for(int h=m/2-1; h>-1; h--)
				{
					if(s1[h]-48!=9)
					{
						s1[h]++;
						break;
					}
					
					s1[h]='0';
				}
				
				printf("%s0",s1);
				tap(s1);
			}
			
			else
			{
				printf("%s%c",s1,++n[m/2]);
				tap(s1);
			}
		}
		
	}
}
