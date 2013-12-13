# include <stdio.h>

int n,m,a,b,v;
int t[100009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		while(m <= a)
		{
			t[b++]=m++;
		}
		
		if(a != t[b-1])
			{v=1; break;}
		
		b--;
	}
	
	if(v == 0)
		printf("Not a proof");
	else
		printf("Cheater");
}
