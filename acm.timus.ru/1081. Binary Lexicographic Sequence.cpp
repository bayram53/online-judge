# include <stdio.h>

int n,m;
int k[50][2];

int main()
{
	scanf("%d %d",&n,&m);
	
	k[1][1]=1;
	k[1][0]=1;
	
	for(int h=2; h<=n; h++)
	{
		k[h][0]=k[h-1][0]+k[h-1][1];
		k[h][1]=k[h-1][0];
	}
	
	if(m>k[n][1]+k[n][0])
	{
		printf("-1");
		return 0;
	}
	
	for(int h=n; h>0; h--)
	{
		if(m>k[h][0])
			printf("1"),m-=k[h][0];
			
		else	
			printf("0");
	}
	
	
}
