# include <stdio.h>
# include <algorithm>

using namespace std;

bool vis[100009];
long long n,k;
long long t[100009];
long long x,y;
int ans[100009],an=0,g=0,a1=0,l=0;

int main()
{
	scanf("%lld %lld",&n,&k);
	
	for(int h=0; h<n; h++)
		scanf("%lld",&t[h]);
		
	x=0;
	y=n-1;
		
	sort(t,t+n);
	
	while(x<=y)
	{
		
		if(x==y)
		{
			ans[a1++]=t[x];
			vis[y]=1;
			
			break;
		}
		
		if(t[x]+t[y]>k)
		{
			ans[a1++]=t[x];
			ans[a1++]=t[y];
			vis[x]=1;
			vis[y]=1;
			x++;
			y--;
		}
		
		else
			x++;
	}
	
	for(int h=0; h<n; h++)
	if(vis[h]==0)
	ans[a1++]=t[h];
	
	g=0;
	an=0;
	
	while(g<n)
	{
		if(ans[g]+ans[g+1]>k) g++;
		else g+=2;
		
		an++;
		
	}
	
	printf("%d\n",an);
	
	for(int h=0; h<n; h++)
		printf("%d ",ans[h]);
}
