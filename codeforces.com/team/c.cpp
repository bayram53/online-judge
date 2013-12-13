# include <stdio.h>

int n, mn, mx;

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		mx = -1;
		mn = 100;
		
		for(int h=0; h<n; h++)
		{
			int a;
			scanf("%d",&a);
			
			if(a < mn)	mn = a;
			if(a > mx)	mx = a;
		}
		
		printf("%d\n",(mx-mn)*2);
	}
}
