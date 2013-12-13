# include <stdio.h>
# include <iostream>

typedef long long llint;

using namespace std;

int n;

llint q[100009],q1,a;

llint k[100009] , k1;

llint d[100009][3],d1;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		cin>>a;
		
		if(!d1  ||  d[d1-1][0] != a)	d[d1++][0] = a;
		
		d[d1-1][1]++;
	}
	
	for(int h=0; h<d1; h++)
	{
		llint e = d[h][1];
		
		while(q1  &&  q[1] < d[h][0])
		{
			del();
		}
		
		if()
	}
}
