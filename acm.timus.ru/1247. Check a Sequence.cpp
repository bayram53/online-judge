# include <stdio.h>

int n , s;
int d[30009];
int ans;
int y;

int main()
{
	scanf("%d %d",&s,&n);
	
	for(int h=1; h<=s; h++)
		scanf("%d",&d[h]) , d[h]--;
	
	for(int h=1; h<=s; h++)
	{
		if(y + d[h] > n  ||  n < d[h])
			ans = 1;
		
		if(y > 0)
			y += d[h];
		else
			y = d[h];
	}
	
	if(ans)
		printf("NO");
	else
		printf("YES");
}
