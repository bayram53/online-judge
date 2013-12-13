# include <stdio.h>
# include <string.h>

int n,pos=1;
char s[10009];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	
	for(int h=1; h<n; h++)
	{
		bool f=0;
		int x=n-h,y=n-1;
		
		while(x<=y)
		{
			if(s[x]!=s[y])
				f=1;
			x++;
			y--;
		}
		
		if(f==0)
			pos=n-h;
	}
	
	printf("%s",s);
	
	for(int h=pos-1; h>-1; h--)
		printf("%c",s[h]);
}
