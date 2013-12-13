# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <stdlib.h>
# include <iostream>
# include <limits.h>

using namespace std;

int n,a,b;
int d[209];
int s,t;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&d[h]) , d[h+n] = d[h];
	
	scanf("%d %d",&s,&t);
	
	if(s > t)
		swap(s ,t);
	
	for(int h=s-1; h<t-1; h++)
		a += d[h];
	
	for(int h=s+n-2; h>t-2; h--)
		b += d[h];
	
	if(a < b)
		printf("%d",a);
	else
		printf("%d",b);
}
