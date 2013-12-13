# include <algorithm>
# include <string.h>
# include <iostream>
# include <stdlib.h>
# define mi(x,y) (x<y ? x : y)

using namespace std;

int n , q , x;
long long y , a;
long long t[400009];

void add(int x,long long y,int l,int r,int s)
{
	t[s] = max(y , t[s]);
	
	if(l == r)
		return ;
	
	if(x <= (l+r)/2)
		add(x , y , l , (l+r)/2 , s*2);
	else
		add(x , y , (l+r)/2+1 , r , s*2+1);
}

long long query(int x,int l,int r,int s)
{
	if(l == r)
		return t[s];
	
	if(x <= (l+r)/2)
		return query(x,l,(l+r)/2,s*2);
	
	return max(t[s*2] , query(x, (l+r)/2+1 , r , s*2+1));
}

int main()
{
	cin>>n;
	
	for(int h=0; h<n; h++)
		cin>>a , add(h+1 , a , 1 , n , 1);
	
	cin>>q;
	
	for(int h=0; h<q; h++)
	{
		cin>>x>>y;
		
		long long k = query(x ,1 , n , 1);
		
		cout<<k<<endl;
		
		add(1 , k + y , 1 , n , 1);
	}
		
}
