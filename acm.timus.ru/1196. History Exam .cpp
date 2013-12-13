# include <stdio.h>
# include <algorithm>

using namespace std;

struct net
{
	int a,b;
};

int n,m,ans=0,l,k=1,b;
int s[15009];
net t[15009];

int binary_search(int r[],int a,int x,int y)
{
	if(abs(x-y)<=1)
	{
		if(r[x]==a)
			return 1;
			
		if(r[y]==a)	
		return 1;
		
		return 0;
	}
	
	if(a==r[(x+y)/2])
		return 1;
	
	if(a<r[(x+y)/2])
		return binary_search(r,a,x,(x+y)/2);
	
	return binary_search(r,a,(x+y)/2+1,y);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&b);
		
		if(k==0 || s[k-1]!=b)
			s[k++]=b;
	}
		
	
	scanf("%d",&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d",&b);
		
		ans+=binary_search(s,b,1,k-1);
	}
	
	printf("%d",ans);
}
