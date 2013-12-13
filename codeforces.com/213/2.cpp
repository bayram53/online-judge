# include <stdio.h>

# define ma(x,y) (x>y ? x : y)
# define MAXN 1000000000

int n, ans = 1;
int D[121121], E[100009];

int main()
{
	scanf("%d",&n);
	
	E[0] = E[1] = 1;
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&D[h]);
		
		if(h < 2)	continue;
		E[h] = D[h] == D[h-1] + D[h-2];
	}
	
	int k = 0, o = 0;
	
	for(int h=0; h<n; h++)
	{
		if(!E[h])	k = 0, o = h+1;
		else k++;
		int a = k;
		if(o > 1)	a += 2;
		else if(o > 0)	a++;
		ans = ma(ans, a);
	}

	int a = k;
	if(o > 1)	a += 2;
	else if(o > 0)	a++;
	ans = ma(ans, k);
	
	printf("%d\n",ans);
}
