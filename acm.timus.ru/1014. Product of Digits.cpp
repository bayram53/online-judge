# include <stdio.h>
# include <algorithm>

using namespace std;

long long n,m=0;
long long t[10009];

int main()
{
	scanf("%lld",&n);
	if(n==0){printf("10\n"); return 0;}
	if(n==1){printf("1\n"); return 0;}
	for(int h=9; h>1; h--)
	while(n%h==0)
	{t[m]=h; m++; n/=h;}
	
	if(n==1)
	for(int h=m-1; h>-1; h--)
	printf("%lld",t[h]);
	else printf("-1");
	printf("\n");
}
