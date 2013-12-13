# include <stdio.h>
# include <string.h>

int n,a=0;
char t[109][100];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%s",t[h]);
	
	for(int h=0; h<n; h++)
	if(t[h][0]!='/')
	{
		a=0;
		
		for(int h1=0; h1<n; h1++)
		if(strcmp(t[h],t[h1])==0 && h!=h1)
		{
			a++;
			t[h1][0]='/';
		}
		
		if(a>0)
			printf("%s\n",t[h]);
			
		t[h][0]='/';
		
	}
}
