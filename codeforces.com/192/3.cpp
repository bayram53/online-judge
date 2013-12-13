# include <stdio.h>

int n;

int r[109][3] , c[109][3];

char s[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",s);
		
		for(int j=0; j<n; j++)
			if(s[j] == '.')
				c[j][0] = r[h][0] = h+1 , c[j][1] = r[h][1] = j+1;
	}
	
	bool p = 0 , g = 0;
	
	for(int h=0; h<n; h++)	if(!r[h][0])	p = 1;
	for(int h=0; h<n; h++)	if(!c[h][0])	g = 1;
	
	if(!p)	for(int h=0; h<n; h++)	printf("%d %d\n",r[h][0],r[h][1]);
	
	else if(!g)	for(int h=0; h<n; h++)	printf("%d %d\n",c[h][0],c[h][1]);
	
	else 	printf("-1");
}
