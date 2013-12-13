# include <stdio.h>
# include <algorithm>
# include <iostream>
# include <string.h>
# include <limits.h>

# define INF INT_MAX
# define mi(x , y) (x < y  ? x  : y)

using namespace std;

int n,a,b=1008,an=0;
int ans[100009][4];
int t[1009][3];
bool d[1009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n-1; h++)
	{
		scanf("%d %d",&t[h][0],&t[h][1]);
		
		d[t[h][0]]=1;
		
		if(t[h][0]==1)
			b=h;
	}
	
	for(int h=1; h<=n; h++)
		if(d[h]==0)
			a=h;
	
	if(b!=1008)
		ans[0][0]=1,ans[0][1]=a,ans[0][2]=1,an++,t[b][0]=a;
	
	for(int h=2; h<=n; h++)
	{
		int o,k=1008;
		for(int j=0; j<n-1; j++)
			if(t[j][0]==h)
				o=j;
				
		for(int j=0; j<n-1; j++)
			if(t[j][1]==h-1)
				k=j;
		
		if(t[o][1]!=h-1)
		{
			ans[an][0]=2;
			ans[an][1]=t[o][1];
			ans[an][2]=h-1;
			an++;
			
			t[k][1]=t[o][1];
			t[o][1]=h-1;
		}
	}
	
	printf("%d\n",an);
	
	for(int h=0; h<an; h++)
		printf("%d %d %d\n",ans[h][0],ans[h][1],ans[h][2]);
}
