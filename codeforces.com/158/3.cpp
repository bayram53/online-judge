# include <iostream>
# include <limits.h>
# define inf LLONG_MAX
# define mi(x,y) (x<y ? x : y)

using namespace std;

long long n,m,e=inf,x=-1;
long long t[1000009];

int main()
{
	cin>>n>>m;
	
	for(int h=0; h<n; h++)
		cin>>t[h],e=mi(e,t[h]);
	
	for(int h=0; h<m; h++)
		if(t[h]==e)
			x=h;
	
	if(x!=-1)
	{
		for(int h=0; h<x; h++)
			t[h]-=t[x];
		
		for(int h=x+1; h<m; h++)
			t[h]-=(t[x]+1);
			
		for(int h=m; h<n; h++)
			t[h]-=t[x];
		
		t[x]=t[x]*n+m-x-1;
		
		for(int h=0; h<n; h++)
			cout<<t[h]<<' ';
	}
	
	else
	{
		for(int h=n-1; h>=m; h--)
			if(e==t[h])
			{
				x=h;
				break;
			}
		
		for(int h=0; h<m; h++)
			t[h]-=(t[x]+1);
		
		for(int h=m; h<x; h++)
			t[h]-=t[x];
			
		for(int h=x+1; h<n; h++)
			t[h]-=(t[x]+1);
		
		t[x]=t[x]*n+n-(x-m+1);
		
		for(int h=0; h<n; h++)
			cout<<t[h]<<' ';
	}
}
