# include <stdio.h>
# include <string.h>

int n, k, m, p[109];

char fi[109][109][50], l[50];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%s",l);
	
	scanf("%d",&k);
	
	for(int h=0; h<k+1; h++)
	{
		scanf("%d",&p[h]);
		
		for(int j=0; j<p[h]; j++)	scanf("%s",fi[h][j]);
	}
	
	scanf("%d",&m);
	
	for(int j=1; j<k+1; j++)
	{
		int tmp = 0;
		
		for(int h=0; h<p[j]; h++)
		{
			bool g = 0;
			
			for(int i=0; i<p[0]; i++)
				if(!strcmp(fi[0][i], fi[j][h]))	g = 1;
			
			tmp += g;
		}
		
		
		if(tmp == p[j])	printf("YES\n");
		else if(p[j]-tmp > n-p[0]-m)	printf("NO\n");
		else 	printf("MAYBE\n");
	}
}
