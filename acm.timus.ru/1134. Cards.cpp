# include <stdio.h>
# include <algorithm>

using namespace std;

int n,k,a;
int t[1009];

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<k; h++)
		scanf("%d",&t[h]);
	
	sort(t,t+k);
	
	for(int h=0; h<n; h++)
	{
		if(k==a || ( h!=t[a] && t[a]!=h+1))
			continue;
		a++;
	}
	
	if(a!=k)
		printf("NO");
	else
		printf("YES");
}
