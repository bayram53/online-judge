# include <stdio.h>
# include <algorithm>

using namespace std;

int ps[202][2],ans=0;
int n;

int cp(int x1,int y1,int x2,int y2,int x3,int y3)
{
	return (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&ps[h][0],&ps[h][1]);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
		{
			int p=0;
			for(int i=0; i<n; i++)
				if(h!=j && i!=j && i!=h && cp(ps[h][0],ps[h][1],ps[j][0],ps[j][1],ps[i][0],ps[i][1])==0)
					p++;
			p+=2;
			ans=max(ans,p);
		}
	printf("%d",ans);
}
