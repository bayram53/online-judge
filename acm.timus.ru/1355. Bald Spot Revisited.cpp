# include <stdio.h>
# include <algorithm>
# include <math.h>

# define mi(x,y) (x<y ? x : y)

using namespace std;

int n,a,b;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		
		if(b%a)	printf("0\n");
		
		else 
		{
			int k = b/a , ans = 0;
			
			for(int h=2; h<=(int)sqrt(k*1.0); h++)
			{
				while(k % h == 0)
				{
					k /= h;
					ans++;
				}
			}
			
			if(k != 1)	ans++;
			
			printf("%d\n",ans+1);
		}
	}
}
