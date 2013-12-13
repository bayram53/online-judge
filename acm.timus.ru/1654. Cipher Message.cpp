# include <stdio.h>
# include <string.h>
# define max 200009

char word[max];
char stack[max];
int n,len=1;

int main()
{
	scanf("%s",word);
	
	n=strlen(word);
	
	stack[0]=word[0];
	
	for(int h=1; h<n; h++)
	{
		if(len==0 || stack[len-1]!=word[h])
			stack[len++]=word[h];
		else
			len--;
	}
	
	for(int h=0; h<len; h++)
		printf("%c",stack[h]);
	
}
