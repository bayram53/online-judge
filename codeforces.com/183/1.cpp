# include <stdio.h>
# include <math.h>

int n,ans;

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
		for(int j=h; j<=n; j++)
			{
				int k = j*j+h*h;
				int p = (int)sqrt(k*1.0);
				
				if(p*p == k  &&  p <= n)	ans++;
			}
	
	printf("%d",ans);
	
}
