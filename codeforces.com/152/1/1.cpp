# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
int mi (int x,int y)
{
	if(x<y)
		return x;
	return y;
}

using namespace std;

int n;
int a,b;
int l,r;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		l+=a;
		r+=b;
	}
	
	
	
	printf("%d",mi(l,n-l)+mi(r,n-r));
}
