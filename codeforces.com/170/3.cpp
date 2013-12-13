# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int n,m,a,b,san;
vector < vector <int> > d(109),s(109);
bool v[109][109];
bool k[109];

void tap(int x)
{
	int a=1,b=0;
	
	k[x] = 1;
	
	int g[109];
	
	g[0] = x;
	
	while(a > b)
	{
		for(int h=1; h<=n; h++)
			if(v[g[b]][h]  &&  !k[h])
				k[h] = 1 , g[a++] = h;
		b++;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		for(int j=0; j<a; j++)
			scanf("%d",&b) , d[b].push_back(h+1) , s[h+1].push_back(b);
	}
	
	for(int h=1; h<=n; h++)
	{
		for(size_t j=0; j<s[h].size(); j++)
			for(size_t i=0; i<d[s[h][j]].size(); i++)
				if(h != d[s[h][j]][i])
					v[h][d[s[h][j]][i]] = 1;
		
	}
	
	for(int h=1; h<=n; h++)
		if(!k[h])
			tap(h) , san++;
	
	
	a=0;
	
	for(int h=1; h<=n; h++)
		if(!(int)s[h].size())
			a++;
	
	if(a == n)
		printf("%d",n);
	else
		printf("%d",san-1);
	
}
