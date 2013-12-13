# include <stdio.h>

# define MAXN 100009

int n, k, D[MAXN], a = 1;

int main()
{
	scanf("%d %d",&n,&k);
	
	if(k == n)
	{
		printf("-1");
		return 0;
	}
	
	if(!k)
	{
		for(int h=2; h<=n; h++)
			D[h] = h-1;
		D[1] = n;
	}
	
	else
	{
		k = n-k;
		
		if(k%2) D[1] = 1, k--, a++;
		
		for(int h=0; h<k/2; h++)
			D[a] = a+1, D[a+1] = a, a += 2;
		
		for(int h=a; h<=n; h++)	D[h] = h;
	}
	
	for(int h=1; h<=n; h++)	printf("%d ",D[h]);
}
