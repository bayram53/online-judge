# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

vector <string> a(1009);
string b;
int t[1009];

int n,j,m=0,ans=0;

int main()
{
	cin>>n;
	
	getline(cin,a[0]);
	
	for(int h=0; h<n; h++)
		getline(cin,a[h]);
	
	
	sort(a.begin(),a.begin()+n);
	
	b=a[0];
	j=0;
	
	for(int h=1; h<n; h++)
	if(b!=a[h])
	{
		t[m++]=h-j;
		j=h;
		b=a[h];
	}
	
	t[m++]=n-j;
	
	for(int h=0; h<m; h++)
	ans+=t[h]-1;
		
	cout<<ans;
}
