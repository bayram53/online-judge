# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <vector>
# include <limits.h>

# define INF INT_MAX

using namespace std;

int n,ans=1;
int t[100009];
int di[100009];
int a[100009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	for(long long h=2; h<=100000; h++)
	{
		if(di[h]==0)
			di[h]=h;
		
		if(h*h>100000)
			continue;
		
		for(int i=h*h; i<=100000; i+=h)
			if(di[i]==0)
				di[i]=h;
	}
	
	for(int h=n-1; h>-1; h--)
	{
		vector <int> b;
		int f=t[h],c=0;
		
		while(f>1)
		{
			b.push_back(di[f]);
			
			f=f/di[f];
		}
		
		for(int j=0; j<(int)b.size(); j++)
			c=max(a[b[j]],c);
		
		c++;
		
		for(int j=0; j<(int)b.size(); j++)
			a[b[j]]=max(a[b[j]],c);
	}
	
	for(int j=0; j<=100000; j++)
		ans=max(a[j],ans);
		
	printf("%d",ans);
}
