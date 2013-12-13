# include <stdio.h>
# include <cstring>
# include <cctype>
# include <algorithm>

using namespace std;

int main()
{
	int n, mas[105], sum[105];
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&mas[h]);
	
	sort(mas, mas+n);
	
	sum[0] = mas[n-1];
	sum[n-1] = mas[0];
	
	for(int h=1; h<n-1; h++)
		sum[h] = mas[h];
	
	for(int h=0; h<n; h++)
		printf("%d",sum[h]);
}
