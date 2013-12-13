# include <stdio.h>
# include <algorithm>

using namespace std;

int n,k,ans=1;
int d[100009];
bool v[100090];

int b_s(int x,int y,int z)
{
	if(abs(y-x) < 2)
	{
		if(d[x] == z)
			return x;
		if(d[y] == z)
			return y;
		return 0;
	}
	
	if(d[(x+y)/2] < z)
		return b_s((x+y)/2 , y , z);
	return b_s(x , (x+y)/2 , z);
}

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&d[h]);
	
	sort(d , d+(n+1));
	v[1] = 1;
	for(int h=2; h<=n; h++)
	{
		int f;
		
		if(d[h] % k == 0)
			f = b_s(1 , h-1 , d[h]/k);
			
		if((d[h] % k == 0  && ( f == 0  ||  v[f] == 0))  ||  d[h] % k)
			ans++,v[h]=1;
		
	}
	
	printf("%d",ans);
}
