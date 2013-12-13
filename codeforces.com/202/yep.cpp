# include <stdio.h>
# include <algorithm>
# include <vector>

# define MAXN 100009

typedef long long lld;

using namespace std;

int n, m, q, sq = 316;
int HS[320], hs;
vector <int> S[MAXN], num[MAXN];
lld D[MAXN], HADD[320], H[320];
int indx[MAXN], common[320][MAXN];
bool heavy[MAXN];

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	
	for(int h=1; h<=n; h++)	scanf("%lld",&D[h]);
	
	for(int h=0; h<m; h++)
	{
		int k;
		scanf("%d",&k);
		S[h].resize(k);
		
		for(int j=0; j<k; j++)	scanf("%d",&S[h][j]);
		
		if(k > sq)
		{
			indx[h] = hs;
			HS[hs++] = h;
			heavy[h] = 1;
			for(int j=0; j<k; j++)	num[S[h][j]].push_back(hs-1), HADD[hs-1] += D[S[h][j]];
		}
	}
	
	for(int h=0; h<m; h++)
		for(int j=0; j<(int)S[h].size(); j++)
		{
			int e = S[h][j];
			
			for(int i=0; i<(int)num[e].size(); i++)
				common[num[e][i]][h]++;
		}
	
	while(q--)
	{
		int x;
		lld y, ret = 0;
		char s[20];
		scanf("%s %d",s,&x);x--;
		
		if(s[0] == '+')
		{
			scanf("%lld",&y);
			
			for(int j=0; j<hs; j++)	HADD[j] += y * common[j][x];
			
			if(!heavy[x])
				for(int j=0; j<(int)S[x].size(); j++)
					D[S[x][j]] += y;
			else
				H[indx[x]] += y;
		}
		
		else
		{
			if(heavy[x])	printf("%lld\n",HADD[indx[x]]);
			
			else
			{
				for(int j=0; j<(int)S[x].size(); j++)
					ret += D[S[x][j]];
				
				for(int j=0; j<hs; j++)	ret += common[j][x]*H[j];
				
				printf("%lld\n",ret);
			}
		}
	}
}
