# include <stdio.h>

int n,m,ans;

char s[109];

bool r[109] , c[109] , p[19][19];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",s);
		
		for(int j=0; j<m; j++)
			if(s[j] == 'S')
				r[h] = 1 , c[j] = 1;
	}
	
	for(int h=0; h<10; h++)
	{
		if(!r[h])
			for(int j=0; j<m; j++)
				p[h][j] = 1;
		
		if(!c[h])
			for(int j=0; j<n; j++)
				p[j][h] = 1;
	}
	
	for(int h=0; h<n; h++)
		for(int j=0; j<m; j++)
			ans += p[h][j];
	
	printf("%d",ans);
}
