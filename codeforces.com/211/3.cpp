# include <stdio.h>
# include <string.h>

# define MAXN 200009
# define mi(x,y) (x<y ? x : y)

char s[MAXN], ns[MAXN], c;

int main()
{
	scanf("%s",s);
	
	int n = strlen(s), p = 0, m = 0;
	c = s[0];
	
	for(int j=0; j<n; j++)
	{
		if(c != s[j])
		{
			for(int h=0; h<mi(2, p); h++)	ns[m++] = s[j-1];
			
			c = s[j];
			p = 0;
		}
		
		p++;
	}
	
	for(int j=0; j<mi(2, p); j++)	ns[m++] = s[n-1];
	
	for(int h=0; h<m-3; h++)
		if(ns[h] == ns[h+1]  &&  ns[h+2] == ns[h+3])
			ns[h+2] = '.';
	
	for(int h=0; h<m; h++)
		if(ns[h] != '.')
			printf("%c",ns[h]);
}
