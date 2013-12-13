# include <stdio.h>

int n,m,s,a;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		if(s + a > 0)
			s += a;
		else
			s = 0;
		
		if(m < s)
			m =s;
	}
	
	printf("%d",m);
}
