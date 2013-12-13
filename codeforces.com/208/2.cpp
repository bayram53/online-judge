# include <stdio.h>
# include <string.h>

# define MAXN 1000009

int n, m = 2, ans = 1;
char s1[MAXN], s2[MAXN], s[MAXN];

int main()
{
	scanf("%d",&n);
	
	s2[0] = '<';
	s2[1] = '3';
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",s);
		
		int k = strlen(s);
		
		for(int j=0; j<k; j++)	s2[m++] = s[j];
		s2[m++] = '<';
		s2[m++] = '3';
	}
	
	scanf("%s",s1);
	
	int a = strlen(s1), b = 0;
	
	for(int h=0; h<a  &&  b < m; h++)
		if(s1[h] == s2[b])	b++;
	
	if(b == m)	printf("yes");
	else 	printf("no");
}
