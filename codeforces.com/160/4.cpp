# include <stdio.h>
# include <iostream>

using namespace std;

int n,p,a,b;
int t[109];
int d[109][2509][2];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	scanf("%d",&p);
	
	for(int h=0; h<n; h++)
	{
		for(int j=0; j<n; j++)
			if(j!=h)
				for(int i=50; i>-1; i--)
				{
					if(i==0)
						d[h][t[j]][0]++,d[h][t[j]][1]+=t[j];
					else if(d[h][i][0]!=0)
						d[h][t[j]+i][0]+=d[h][j][0],d[h][t[j]+i][1]+=d[h][j][0];
				}
	}
	
}
