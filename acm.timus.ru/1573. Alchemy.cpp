# include <stdio.h>

int a,b,c,ans=1;
int k;
char c1[89];

int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&k);
	
	for(int h=0; h<k; h++)
	{
		scanf("%s",c1);
		
		if(c1[0] == 'B')
			ans *= a;
		else if(c1[0] == 'R')
			ans *= b;
		else
			ans *= c;
	}
	
	printf("%d",ans);
	
}
