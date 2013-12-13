# include <stdio.h>
# include <string.h>
# include <math.h>

struct mal
{
	int a;
	bool d[20];
};

int n,p=1;

mal dp[1000009];

int f[20];

int mod[35];

void print(int x)
{
	for(int h=0; h<dp[x].a; h++)
	{
		int k = dp[x].d[h];
		printf("%d",k+1);
	}
}

void tap(int x,int y,int z)
{
	if(x == y)
	{
		int ret = 0;
		
		if(z == 0)
		{
			for(int h=x-1; h>-1; h--)	ret += mod[x-1-h]*f[h] , ret %= n;
			
			if(!dp[ret].a)
			{
				//if(!ret)	printf("mal");
				
				dp[ret].a = x;
				for(int h=0; h<x; h++)	dp[ret].d[h] = f[h]-1;
			}
		}
		
		if(z == 1)
		{
			for(int h=x-1; h>-1; h--)	ret += mod[x-1-h]*f[h] , ret %= n;
			
			if(dp[ret].a != 18)
			{
				dp[ret].a = x;
				
				for(int h=0; h<x; h++)	dp[ret].d[h] = f[h]-1;
			}
			
		}
		
		if(z == 2)
		{
			for(int h=x-1; h>-1; h--)
			{
				ret += mod[x-1-h+18]*f[h];
				ret %= n;
			}
			
			if(dp[n-ret].a == 18  &&  p)
			{
				p = 0;
				for(int h=0; h<x; h++)	printf("%d",f[h]);
				print(n-ret);
				
			}
		}
	}
	
	else
	{
		f[y] = 1;	tap(x,y+1,z);
		f[y] = 2;	tap(x,y+1,z);
	}
}

int main()
{
	memset(dp , 0 , sizeof(dp));
	
	scanf("%d",&n);
	
	mod[0] = 1;
	
	for(int h=1; h<32; h++)	mod[h] = (10*mod[h-1])%n;
	
	for(int h=1; h<19; h++)	tap(h,0,0);
	
	if(dp[0].a)	print(0) , p = 0;
	
	tap(18,0,1);
	
	for(int h=1; h<13; h++)	tap(h,0,2);
	
	if(p)	printf("Impossible");
}
