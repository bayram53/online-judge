# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <vector>

using namespace std;

int n,q;
int l,r;
int d[100009];
int b[100009];
int uly[100009];
int kici[100009];

int main()
{
	scanf("%d %d",&n,&q);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&d[h]);
	
	for(int h=1; h<n; h++)
	{
		if(d[h] < d[h+1])
			b[h] = 1;
		if(d[h] > d[h+1])
			b[h] = 2;
	}
	
	int x = 0;
	
	for(int h=1; h<=n; h++)
	{
		if(b[h] == 1)
			x = h;
		kici[h] = x;
	}
	
	x = n;
	
	for(int h=n; h>0; h--)
	{
		if(b[h] == 2)
			x = h;
		uly[h] = x;
	}
	
	
	for(int h=0; h<q; h++)
	{
		scanf("%d %d",&l,&r);
		
		if(uly[l] > kici[r-1])
			printf("Yes\n");
		else
			printf("No\n");
	}
}
