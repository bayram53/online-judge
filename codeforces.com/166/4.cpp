# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>
# include <vector>
# include <limits.h>

using namespace std;

int n ,k;
string s;
int t[100];
int d[1509];
vector <string> r(2250009);

int main()
{
	cin>>s;
	
	for(int h=0; h<26; h++)
		scanf("%d",&t[h]);
	
	scanf("%d",&k);
	
	n = s.length();
	
	for(int h=1; h<=n; h++)
		d[h] = d[h-1] + t[s[h-1]-97];
	
	for(int h=0; h<n; h++)
		for(int j=h+1; j<n; j++)
		if()
		{
			
			
		}
}
