#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define ll long long

int n, m, q;
int llist[350][100005];
int a[100005];
ll sum[100005];
bool heavy[100005];
ll hid[100005], hnum;
int sq = 300;
vector<int> s[100005], num[100005], hlist;

ll add[100005], hadd[100005], sadd[100005];

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
	for(int i=0; i<n; i++) scanf("%d",a+i);
    
    for(int i = 0; i<m; i++)
	{
		int sz;
		
		scanf("%d",&sz);
		
		for(int j=0; j<sz; j++)
		{
			int id;
			scanf("%d",&id); id--;
			s[i].pb(id);  
			num[id].pb(i);
			sum[i] += a[id];
		}
    }
    
    for(int i=0; i<m; i++)
		if((int)s[i].size() >= sq)
		{
			hid[i] = hnum++;
			heavy[i] = true;
			hlist.pb(i);
		}
    
	for(int i=0; i<(int)hlist.size(); i++)
	{
		int id = hlist[i];
		
		for(int j=0; j<(int)s[id].size(); j++)
		{
			int cur = s[id][j];
			for(int k=0; k<(int)num[cur].size(); k++) llist[i][num[cur][k]]++;
		}
	}
	
    while(q--)
    {
		char c;
		int x;
		
		scanf(" %c%d",&c,&x); x--;
		
		if(c == '?')
		{
			ll res = sum[x];
			
			for(int i=0; i<hnum; i++) res += llist[i][x] * add[i];
			
			if(heavy[x])
				res += hadd[hid[x]];
			
			else
				for(int i=0; i<(int)s[x].size(); i++) res += sadd[s[x][i]];
			
			printf("%lld\n",res);
		}
		else
		{
			int y;
			scanf("%d",&y);
			
			if(!heavy[x])
			{
				for(int i=0; i<(int)s[x].size(); i++) sadd[s[x][i]] += y;
				for(int i=0; i<hnum; i++) hadd[i] += y * 1LL * llist[i][x];
			}
			
			else
				add[hid[x]] += y;
		}
	}
    return 0;
}
