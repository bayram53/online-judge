# include <iostream>
# include <limits.h>
# include <algorithm>
# define INF LLONG_MIN/2
# define ma(x,y) (x>y ? x : y)

typedef long long llint;

using namespace std;

llint n,d;

llint t[1009][3];

llint g[109][109];

llint f[109];

llint dist(int x,int y)
{
	return (abs(t[x][0]-t[y][0])+abs(t[x][1]-t[y][1]))*d;
}

int main()
{
	cin>>n>>d;
	
	for(int h=1; h<n-1; h++)	cin>>f[h];
	
	for(int h=0; h<n; h++)	cin>>t[h][0]>>t[h][1];
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			if(h != j)
				g[h][j] = -1*dist(h,j)+f[h]+f[j];
	
	/*for(int h=0; h<n; h++)
	{
		for(int j=0; j<n; j++)	cout<<g[h][j]<<' ';
		cout<<endl;
	}*/
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			for(int i=0; i<n; i++)
				if(g[i][j] < g[i][h] + g[h][j] - f[h])	g[i][j] = g[i][h] + g[h][j] - f[h];
	
	
	/*cout<<"_______\n";
	for(int h=0; h<n; h++)
	{
		for(int j=0; j<n; j++)	cout<<g[h][j]<<' ';
		cout<<endl;
	}*/
	
	cout<<ma(g[0][n-1]*-1,0);
}
