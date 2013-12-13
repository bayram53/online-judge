# include <stdio.h>

# define mi(x,y) (x<y ? x : y)

int n,ans=100009;

int d[29];

bool f[29];

void tap(int x)
{
	if(x == n)
	{
		int k = 0;
		
		for(int h=0; h<n; h++)
		{
			if(f[h])	k += d[h];
			else 	k -= d[h];
		}
		
		if(k < 0)	k *= -1;
		
		ans = mi(ans,k);
	}
	
	else
	{
		f[x] = 0;	tap(x+1);
		f[x] = 1; 	tap(x+1);
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&d[h]);
	
	tap(0);
	
	printf("%d",ans);
}
