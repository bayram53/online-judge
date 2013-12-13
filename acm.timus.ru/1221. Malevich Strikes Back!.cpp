# include <stdio.h>

# define ma(x,y) (x>y ? x : y)

int n;

int d[109][109];

int tap(int x,int y)
{
	if(x/2+2 > y)	return y*2-1;
	return x-2*(y-x/2-1);
}

int main()
{
	//for(int h=1; h<10; h++)	printf("f(%d,%d) = %d\n",9,h,tap(9,h));
	
	scanf("%d",&n);
	
	while(n)
	{
		int ans=0;
		
		for(int h=1; h<=n; h++)
			for(int j=1; j<=n; j++)
				scanf("%d",&d[h][j]);
		
		for(int h=1; h<=n; h++)
			for(int j=2; j<=n; j++)
				d[h][j] += d[h][j-1];
		
		for(int h=1; h<=n; h++)
			for(int j=h+2; j<=n; j+=2)
			{
				int k = j-h+1, b = 1;
				
				for(int i=1; i<=n; i++)
				{
					int a = tap(k,b);
					
					if((k-a)/2 == d[i][h-1+(k-a)/2]-d[i][h-1]  &&  (k-a)/2 == d[i][j]-d[i][j-(k-a)/2]  &&
					d[i][j-(k-a)/2]-d[i][h-1+(k-a)/2] == 0)	b++;
					else
					{
						b = 1;
						
						a = tap(k,b);
						
						if((k-a)/2 == d[i][h-1+(k-a)/2]-d[i][h-1]  &&  (k-a)/2 == d[i][j]-d[i][j-(k-a)/2]  &&
						d[i][j-(k-a)/2]-d[i][h-1+(k-a)/2] == 0)	b++;
					}
					
					if(b == k+1)	{ans = ma(ans,k);break;}
				}
			}
		
		if(ans)	printf("%d\n",ans);
		else 	printf("No solution\n");
		
		scanf("%d",&n);
	}
	
}
/*8
1 0 1 1 0 1 1 1
0 0 0 1 0 1 1 1
1 0 1 1 0 1 1 1
1 1 1 1 0 1 1 1
1 1 1 0 0 0 1 1
1 1 0 0 0 0 0 1
1 1 1 0 0 0 1 1
1 1 1 1 0 1 1 1*/
