# include <stdio.h>
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

int n,a=-1,b=99,a1;
int ans=0;
char c[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %s",&a1,c);
		
		if(c[0]=='h')
			a=ma(a,a1);
			
		else
			b=mi(a1,b);
			
		if(a!=-1 && b!=99 && b<=a)
			ans=1;
	}
	
	if(b==99 && ans==0)
		printf("10");
	
	else if(ans==0)
		printf("%d",b);
	
	else
		printf("Inconsistent");
	
	
}
