# include <stdio.h>

int n, ans;

char s[10], k[10];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",s);
		
		if(h  &&  k[1] == s[0])	ans++;
		
		k[1] = s[1];
	}
	
	printf("%d\n",ans+1);
}
