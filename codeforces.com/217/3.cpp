# include <stdio.h>
# include <algorithm>

# define MAXN 5009

using namespace std;

int n, m, L[MAXN], A[MAXN][3], ans, R[MAXN], C[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)	scanf("%d",&L[h]), R[h] = L[h], C[L[h]]++;
	
	sort(L, L+n);
	
	for(int h=0; h<n; h++)
	{
		A[h][0] = L[h];
		R[n] = L[h];
		int mx = -1, pos = n;
		
		for(int j=0; j<n; j++)	if(R[j]  &&  mx < C[R[j]]  &&  R[j] != L[h])	pos = j, mx = C[R[j]];
		
		A[h][1] = R[pos];
		C[L[h]]--;
		R[pos] = 0;
		
		ans += A[h][0] != A[h][1];
	}
	
	printf("%d\n",ans);
	
	for(int h=0; h<n; h++)	printf("%d %d\n",A[h][0],A[h][1]);
}
