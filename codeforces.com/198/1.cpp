# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <string.h>
# include <vector>

using namespace std;

int gcd(int n,int m)
{
	if(m==0)	return n;
	
	return gcd(m,n%m);
}

int x,y,a,b,ans;

int main()
{
	scanf("%d %d %d %d",&x,&y,&a,&b);
	
	int k = (x*y)/gcd(x,y);
	
	ans = b/k-(a-1)/k;
	
	printf("%d\n",ans);
}
