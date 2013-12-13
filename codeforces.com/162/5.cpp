# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <limits.h>
# define INF LLONG_MAX
typedef long long llint;

using namespace std;

int n,q;
llint v[100009];
llint c[100009];
llint co[100009][2];

int main()
{
	cin>>n>>q;
	
	for(int h=0; h<n; h++)
		cin>>v[h];
	
	for(int h=0; h<n; h++)
		cin>>c[h];
	
	for(int h=0; h<q; h++)
	{
		int a,b;
		llint x,x1,y=-INF,y1=INF,ans=0;
		
		cin>>a>>b;
	
		memset(co,0,sizeof(co));
	
		x1=c[0];
		x=b*v[0];
		co[c[0]][1]=1;
		co[c[0]][0]=x;
		
		
		
		for(int j=1; j<n; j++)
		{
			llint o=-INF;
			
			if(co[c[j]][1] != 0)
				o=max(o,co[c[j]][0]+a*v[j]);
			o=max(o,b*v[j]);
			
			if(x1 == c[j]  &&  y1 != INF)
				o=max(o,y+b*v[j]);
			else if(x1 != c[j])
				o=max(o,x+b*v[j]);
			
			ans=max(o,ans);
			
			//cout<<x<<' '<<x1<<"__"<<y<<' '<<y1<<endl;
			
			if(o < co[c[j]][0]  &&  co[c[j]][1] == 1)
				continue;
				
			co[c[j]][1]=1;
			co[c[j]][0]=o;
			
			if(x1 == c[j])
				x=o;
			else if(x <= o)
				y=x,y1=x1,x=o,x1=c[j];
			else if(y <= o)
				y=o,y1=c[j];
		}
		
		cout<<ans<<endl;
	}
}
