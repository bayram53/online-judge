# include <stdio.h>
# include <algorithm>
# include <vector>

using namespace std;

int n,m,a,b,er;
vector < vector <int> > d(109);
int k[109],k1;
int f[109][6],f1;
bool v[109];

void tap(int a)
{
	int x=1,y=0;
	int r[100009];
	r[0] = a;
	v[a] = 1;
	while(x > y)
	{
		int to = r[y];
		
		for(int h=0; h<(int)d[to].size(); h++)
			if(v[d[to][h]] == 0)	r[x++] = d[to][h] , v[d[to][h]] = 1;
		y++;
	}
	if(x > 3)	{er=1;return ;}
	if(x == 1)	k[k1++] = a;
	if(x == 2)
	{
		int p = 1;
		
		for(int h=0; h<n/3; h++)
			if(f[h][5] < 2)
			{
				p = 0;
				int to = f[h][5];
				f[h][to] = r[0];
				f[h][to+1] = r[1];
				f[h][5] += 2;
				break;
			}
		if(p)	er = 1;
	}
	
	if(x == 3)
	{
		int p = 1;
		
		for(int h=0; h<n/3; h++)
			if(!f[h][5])
			{
				p = 0;
				int to = f[h][5];
				f[h][to] = r[0];
				f[h][to+1] = r[1];
				f[h][to+2] = r[2];
				f[h][5] += 3;
				break;
			}
		if(p)	er = 1;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	
	for(int h=1; h<=n; h++)
		if(!v[h])
		{
			tap(h);
			if(er)	{printf("-1");return 0;}
		}
	
	for(int h=0; h<k1; h++)	
	{
		for(int j=0; j<n/3; j++)
			if(f[j][5] < 3)
				{f[j][f[j][5]] = k[h]; f[j][5]++; break;}
	}
	
	for(int h=0; h<n/3; h++)
		printf("%d %d %d\n",f[h][0],f[h][1],f[h][2]);
}
