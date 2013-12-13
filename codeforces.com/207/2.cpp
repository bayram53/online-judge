# include <stdio.h>
# include <vector>
# include <algorithm>

# define MAXN 100009

using namespace std;

struct mal
{
	
};

int n, m;
vector <int> D[MAXN], K;
int col[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		
		D[a].push_back(b);
		D[a].push_back(c);
		D[b].push_back(a);
		D[b].push_back(c);
		D[c].push_back(b);
		D[c].push_back(a);
		
		if((int)D[a].size() == 4)	K.push_back(a);
		if((int)D[b].size() == 4)	K.push_back(b);
		if((int)D[c].size() == 4)	K.push_back(b);
	}
	
	for(int h=0; h<(int)K.size(); h++)
	{
		bool s[10];
		s[1] = s[2] = s[3] = 0;
		int to = K[h];
		
		for(int j=0; j<(int)D[to].size(); j++)	s[col[D[to][j]]] = 1;
		
		for(int j=1; j<4; j++)
			if(!s[j])
			{
				col[to] = j;
				break;
			}
	}

	for(int h=1; h<=n; h++)
	if(!col[h])
	{
		bool s[10];
		s[1] = s[2] = s[3] = 0;
		
		for(int j=0; j<(int)D[h].size(); j++)	s[col[D[h][j]]] = 1;
		
		for(int j=1; j<4; j++)
			if(!s[j])
			{
				col[h] = j;
				break;
			}
	}	
	for(int h=1; h<=n; h++)	printf("%d ",col[h]);
}
