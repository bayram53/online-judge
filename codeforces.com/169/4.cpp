# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <iostream>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

typedef long long llint;

llint l,r;
llint ans,a,b;
int x[99],e1;
int y[99],e2;

int main()
{
	cin>>l>>r;
	
	a = l; b = r;
	llint d = r;
	
	while(d)
	{
		x[e1++] = d % 2;
		d /= 2;
	}
	
	d = l;
	
	while(d)
	{
		y[e2++] = d % 2;
		d /= 2;
	}
	
	d = e1;
	
	for(int h=0; h<e1/2; h++)
		swap(y[h] , y[--d]) , swap(x[h] , x[d]);
	
	for(int h=0; h<e1; h++)
	{
		if(x[h] != y[h])
			{
				ans += (llint)pow(2.0 , (double)(e1 - h - 1));
				continue;
			}
		
		if(x[h] == 1  &&  b - (llint)pow(2.0 , (double)(e1 - h - 1)) >= l)
		{
			ans += (llint)pow(2.0 , (double)(e1 - h - 1));
			b -= (llint)pow(2.0 , (double)(e1 - h - 1));
		}
		
		else if(x[h] == 0  &&  a + (llint)pow(2.0 , (double)(e1 - h - 1)) <= r)
		{
			ans += (llint)pow(2.0 , (double)(e1 - h - 1));
			a += (llint)pow(2.0 , (double)(e1 - h - 1));
		}
	}
	
	cout<<ans;
}
