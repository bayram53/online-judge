# include <stdio.h>
# include <algorithm>
# include <limits.h>
# include <vector>

# define INF INT_MIN
# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

using namespace std;

int n,a,b,e;

vector < vector <int> > ch(6009);

int dp[6009][3];

int cost[6009];

bool v[6009];

int tap(int x,int y)
{
	if(dp[x][y] != INF)	return dp[x][y];
	
	if((int)ch[x].size() == 0)
	{
		dp[x][0] = 0;
		dp[x][1] = cost[x];
		
		return dp[x][y];
	}
	
	dp[x][y] = 0;
	
	for(int h=0; h<(int)ch[x].size(); h++)
	{
		int k = 0;
		
		k = ma(k , tap(ch[x][h],0));
		if(!y)	k = ma(k , tap(ch[x][h],1));
		
		dp[x][y] += k;
	}
	
	if(y)	dp[x][y] += cost[x];
	
	return dp[x][y];
}

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)	dp[h][0] = dp[h][1] = INF;
	
	for(int j=1; j<=n; j++)	scanf("%d",&cost[j]);
	
	scanf("%d %d",&a,&b);
	
	while(a)
	{
		ch[b].push_back(a);
		v[a] = 1;
		scanf("%d %d",&a,&b);
	}
	
	for(int h=1; h<=n; h++)
		if(v[h] == 0) e = h;
	
	printf("%d",ma(tap(e,0),tap(e,1)));
}
