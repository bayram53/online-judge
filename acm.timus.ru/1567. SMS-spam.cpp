# include <stdio.h>

int n;
int ans;
char c[1009];

int main()
{
	while (scanf("%c",&c[n]), c[n]!='\n')
	n++;
	
	for(int h=0; h<n; h++)
	{
		if(c[h]==' ')
		ans++;
		else
		{
			int a=(int)c[h];
			if(c[h]!='_') 
			{
				if(a%3==0) ans+=3;
				else ans+=(a%3);
			}
			else ans++;
		}
	}
	printf("%d",ans);
}

