# include <stdio.h>
# include <algorithm>

using namespace std;

int a,n;
int t[10000];
int ans=1,x=0;

int main()
{
	for(int h=0; h<10; h++)
	{
		scanf("%d",&a);
		
		int d=2;
		int o=a;
		
		while(d<=o)
		{
			while(a%d==0)
				t[n++]=d,a/=d;
			d++;
		}
	}
	
	sort(t,t+n);
	
	
	for(int h=1; h<n; h++)
		if(t[h]!=t[h-1])
		{
			ans*=(h-x+1);
			ans%=10;
			x=h;
		}
		
	ans*=(n-x+1);
	ans%=10;
	
	printf("%d\n",ans);
}
