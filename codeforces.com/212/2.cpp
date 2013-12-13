# include <stdio.h>
# include <algorithm>

using namespace std;

int n, m, ans;
int D[3009];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)	scanf("%d",&D[h]);
	
	sort(D, D+m);
	
	if(D[0] == 1  ||  D[m-1] == n)	{printf("NO"); return 0;}
	
	for(int h=2; h<m; h++)
		if(D[h] == D[h-1]+1  &&  D[h-1] == D[h-2]+1)	ans = 1;
		
	if(ans)	printf("NO");
	else 	printf("YES");
}
