# include <stdio.h>

int n;

int main()
{
	scanf("%d",&n);
	
	if(n>-1)	printf("%d",n);
	
	else
	{
			int k = n*-1;
			
			if(k%10 > k%100/10)	printf("%d",n/10);
			else 	printf("%d",(n/100)*10-(k%10));
	}
}
