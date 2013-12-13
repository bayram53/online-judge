# include <stdio.h>
# include <algorithm>

using namespace std;

int n;

int D[1009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&D[h]);
	
	sort(D, D+n);
	
	printf("%d ",D[n-1]);
	
	for(int h=1; h<n-1; h++)	printf("%d ",D[h]);
	
	printf("%d",D[0]);
}
