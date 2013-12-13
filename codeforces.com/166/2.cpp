# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>
# include <vector>
# include <limits.h>
# define mi(x,y) (x < y ? x : y)

int n,a,ans = INT_MAX , m;
int t[200009];
int d[200009];
int v[509][509];

int main()
{
	for(int h1=2; h1<200000; h1++)
	{
		int r = h1;
		
		if(t[r] == 0)
			t[r] = r; 
		
		if(r > 1000)
			continue;
		
		for(int j=r*r; j<200001; j+=r)
				t[j] = r;
	}
	
	int s = 0;
	
	for(int h=100000; h<200000; h++)
		if(t[h] == h)
		{
			s = h;
			break;
		}
	
	int k =s;
	
	for(int h=s; h>0; h--)
	{
		if(t[h] == h)
			k =h;
		
		d[h] = k;
	}
	
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<m; j++)
		{
			scanf("%d",&a);
			
			v[h][j] = d[a] - a;
		}
	
	for(int h=0; h<n; h++)
	{
		int p = 0;
		
		for(int j=0; j<m; j++)
			p += v[h][j];
		
		ans = mi(ans, p);
	}
	
	for(int h=0; h<m; h++)
	{
		int p = 0;
		
		for(int j=0; j<n; j++)
			p += v[j][h];
		
		ans = mi(ans, p);
	}
	
	printf("%d\n",ans);
}
