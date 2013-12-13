# include <stdio.h>
# include <limits.h>

# define INF INT_MAX

int mx = INF, n, D[200009], k, ans;

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=1; h<=n; h++)	scanf("%d",&D[h]), D[h] += D[h-1];
	
	for(int h=1; h<=n-k+1; h++)	if(mx > D[h+k-1] - D[h-1])	ans = h, mx = D[h+k-1] - D[h-1];
	
	printf("%d\n",ans);
}
