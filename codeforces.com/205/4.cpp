# include <stdio.h>
# include <string.h>

# define MAXN 1000009
# define ma(x,y) (x>y ? x : y)

int n, k, a = 0, ans, bekle;

int P[MAXN], prev[MAXN];

char s[MAXN];

int main()
{
	scanf("%s",s);
	
	n = strlen(s);
	
	for(int h=n; h>0; h--)	s[h] = s[h-1];
	
	for(int h=1; h<=n; h++)
	{
		if(s[h] == 'F')
		{
			k++;
			if(h > 1)	bekle = ma(0, bekle+1-(h-a-1));
			if(k == h)	bekle = 0;
			if(k != h)	ans = ma(ans, bekle+(h-k));
			printf("%d",bekle);
			a = h;
		}
		else 	printf("0");
	}
	
	printf("%d\n",ans);
}
