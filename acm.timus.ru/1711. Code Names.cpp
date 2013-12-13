# include <iostream>
# include <algorithm>
# include <string.h>
# include <string>
# include <vector>

using namespace std;

int n;
vector < vector<string> > a(20);
string c;
int t[20];

int main()
{
	for(int h=0; h<20; h++)
		a[h].resize(3);
	
	cin>>n;
	
	for(int h=0; h<n; h++)
	{
		cin>>a[h][0]>>a[h][1]>>a[h][2];
		
		sort(a[h].begin() , a[h].end());
	}
	
	for(int h=0; h<n; h++)
		cin>>t[h] , t[h]--;
	
	c = a[t[0]][0];
	
	for(int h=1; h<n; h++)
	{
		if(c > a[t[h]][2])
		{
			cout<<"IMPOSSIBLE";
			return 0;
		}
		
		if(c <= a[t[h]][0])
			c = a[t[h]][0];
		else if(c <= a[t[h]][1])
			c = a[t[h]][1];
		else
			c = a[t[h]][2];
	}
	
	c = a[t[0]][0];
	
	for(int h=1; h<n; h++)
	{
		cout<<c<<endl;
		
		if(c <= a[t[h]][0])
			c = a[t[h]][0];
		else if(c <= a[t[h]][1])
			c = a[t[h]][1];
		else
			c = a[t[h]][2];
	}
	
	cout<<c;
}
