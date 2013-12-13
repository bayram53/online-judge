# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <iostream>
# include <stdlib.h>
# include <vector>

using namespace std;

int n;
int a[100009];
int b[100009];
int e[200009];
long long mod;
long long ans = 1;
vector < vector <int> > t(200009);

int b_s(int l,int r ,int x)
{
	if(abs(l - r) < 2)
	{
		if(e[l] == x)
			return l;
		return r;
	}
	
	if(e[(l+r)/2] > x)
		return b_s(l , (l+r)/2 , x);
	return b_s((l+r)/2 , r , x);
}

int main()
{
	cin>>n;
	
	for(int h=0; h<n; h++)
		cin>>a[h] , e[h + 1] = a[h];
	for(int h=0; h<n; h++)
		cin>>b[h] , e[n + h +1] = b[h];
	
	cin>>mod;
	
	e[0] = -1;
	
	sort(e , e + (n*2+1));
	
	for(int h=0; h<n; h++)
		t[b_s(1, 2*n , a[h])].push_back(h+1);
	
	for(int h=0; h<n; h++)
		t[b_s(1, 2*n , b[h])].push_back(h+1);
	
	for(int h=0; h<200009; h++)
		sort(t[h].begin(),t[h].end());
	
	for(int h=0; h<200009; h++)	
	if((int)t[h].size() > 1)
	{
		long long e=0;
		long long r=1;
		
		for(int j=1; j<(int)t[h].size(); j++)
			if(t[h][j] == t[h][j-1])
				e++;
		
		for(int j=2; j<=(int)t[h].size(); j++)
		{
			int g = j;
			
			if(g % 2 == 0  &&  e != 0)
				g /= 2 , e--;
			
			r *= g;
			r %= mod;
		}
		
		ans *= r;
		ans %= mod;
	}
	
	cout<<ans;
}
