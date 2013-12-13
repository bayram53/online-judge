# include <stdio.h>
# include <algorithm>

using namespace std;

int l1,l2,n1,n2;

int main()
{
	scanf("%d %d %d %d",&l1,&l2,&n1,&n2);
	
	printf("%d",abs( ( n2 - n1 ) * ( l1 + 2 * l2 ) - l1 ));
}
