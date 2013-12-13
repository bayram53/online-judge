# include <stdio.h>
# include <algorithm>

using namespace std;

int n,m,ans=1;
int t[10009];

int main()
{
	scanf("%d %d",&n,&m);
	
	t[m]=1;
	
	for(int h=m; h<=n; h++)
	if(t[h]!=0)
	{
		for(int j=1; j<=100; j++)
		{
			double mal1=(double)h*(double)j/100.0;
			int mal2=h*j/100;
			
			if(mal1-(double)mal2!=0.0)
				continue;
			
			if(mal2+h>n)
				continue;
			
			t[h+mal2]=max(t[h+mal2],t[h]+1);
			ans=max(ans,t[h+mal2]);
		}
	}
	
	printf("%d\n",ans);
}
