# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <iostream>

# define mi(x,y) (x<y ? x : y)
# define INF INT_MAX

using namespace std;

long long ans;
int n,m,l;
int d[200009];
int k[200009];
int a,b;
int s;
int p[200009],e;

int main()
{
	cin>>n>>m;
	
	for(int h=0; h<n; h++)
		scanf("%d",&d[h]);
	
	sort(d , d+n);
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d",&a,&b);
		
		k[a]++;
		k[b+1]--;
	}
	
	for(int h=0; h<200001; h++)
	{
		s += k[h];
		
		if(s != 0)
			p[e++] = s;
	}
	
	
	l = n;
	sort(p , p+e);
	
	for(int h=e-1; h>-1; h--)
		ans += (long long)p[h]*d[--l];
	
	cout<<ans;
}
