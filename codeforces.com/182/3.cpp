# include <stdio.h>
# include <algorithm>

using namespace std;

int n;

int e=1009,a,b,d,m;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<2*n-1; h++)
	{
		scanf("%d",&b);
		a += abs(b);
		if(e > abs(b))	e = abs(b);
		if(b < 0)	m++;
		if(b == 0)	d = 1;
	}
	
	if(d  ||  n%2  ||  m%2 == 0)	printf("%d",a);
	else printf("%d",a-e-e);
}
