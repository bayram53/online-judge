# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <vector>

using namespace std;

int n,a;

int T[100009];

int f(int x)
{
	return (x) & (-x);
}

void add(int i,int x)
{
	while(i <= n)
	{
		T[i] = max(x,T[i]);
		i=i+f(i);
	}
}

int query(int i)
{
	int san=0;
	
	while(i>0)
	{
		san = max(san,T[i]);
		i=i-f(i);
	}
	
	return san;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		int k = query(a);
		
		add(a,k+1);
	}
	
	printf("%d\n",query(n));
}

