# include <stdio.h>
# include <algorithm>
# include <vector>

using namespace std;

int n;
int t[3][111];

int main()
{
	scanf("%d",&n);
	
	t[0][0] = 6;
	t[0][1] = 3;
	t[0][100]  = 2;
	
	for(int h=2; h<=n; h++)
	{
		int  k=0;
		
		for(int j=0; j<t[h%2][100]; j++)
			t[2][j+1] = (t[h%2][j]*5 + k) % 10 ,  t[(h+1)%2][j] = (t[h%2][j]*5 + k) % 10  ,  k = (t[h%2][j]*5 + k) / 10;
		
		t[(h+1)%2][100] = t[h%2][100];
		
		if(k != 0)
			t[2][t[h%2][100]+1] = k , t[(h+1)%2][t[h%2][100]] = k , t[(h+1)%2][100]++;
		
		t[(h+1)%2][t[(h+1)%2][100]] = 0;
		k = 0;
		
		for(int j=1; j<=t[(h+1)%2][100]; j++)
		{
			int p = (t[(h+1)%2][j] + k + t[2][j]);
			
			t[(h+1)%2][j] = p%10;
			k = p / 10;
		}
		
		t[(h+1)%2][100]++;

		if(k != 0)
			t[(h+1)%2][100]++ , t[(h+1)%2][t[(h+1)%2][100]-1] = k;
	}
	
	for(int h = t[(n+1)%2][100]-1; h>-1; h--)
		printf("%d",t[(n+1)%2][h]);
}
