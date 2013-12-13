# include <stdio.h>

int n, ans, x, y;
int D[1009];

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)	scanf("%d",&D[h]);
	scanf("%d %d",&x,&y);
	
	for(int h=2; h<=n; h++)
	{
		int a = 0;
		int b = 0;
		
		for(int j=h; j<=n; j++)	a += D[j];
		for(int j=1; j<h; j++)	b += D[j];
		
		if((x <= a  &&  a <= y)  &&  (x <= b  &&  b <= y))	ans = h;
	}
	
	printf("%d\n",ans);
}
