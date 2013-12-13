# include <stdio.h>

int n,x,y,p;

int d[1009];

int t[1009];

int kn[1009],a;

int dp[2009];

int main()
{
	scanf("%d %d",&n,&x);
	
	for(int h=0; h<n; h++)	scanf("%d",&d[h]) , t[d[h]] = h+1;
	
	for(int h=1; h<=n; h++)
	{
		if(d[h-1])	continue;
		
		int o=0,l=h,i=0;
		
		while(1)
		{
			if(l == x) p = o+1 , i = 1;
			o++;
			if(!t[l])	break;
			l = t[l];
		}
		
		if(!i)	kn[a++] = o;
	}
	
	dp[0] = 1;
	
	for(int j=0; j<a; j++)
		for(int h=1000; h>-1; h--)
			if(dp[h])	dp[h+kn[j]] = 1;
	
	for(int h=0; h<1009; h++)
		if(dp[h])
			printf("%d\n",h+p);
}

