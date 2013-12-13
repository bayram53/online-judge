# include <stdio.h>
# include <string.h>
# include <iostream>
#include <algorithm>

# define si dp[h][j].sz

using namespace std;

struct mal
{
	string s;
	int sz;
} dp[109][109];

string s1, s2, virus;

int main()
{
	for(int h=1; h<102; h++)
		for(int j=1; j<102; j++)
			si = 0;
	
	cin>>s1>>s2>>virus;
	
	int a = s1.length();
	int b = s2.length();
	int c = virus.length();
	
	for(int h=1; h<=a; h++)
		for(int j=1; j<=b; j++)
		{
			if(s1[h-1] == s2[j-1])
			{
				dp[h][j] = dp[h-1][j-1]; dp[h][j].s += s1[h-1]; si++;
				
				if(si >= c)
				{
					string f = dp[h][j].s.substr(si-c, si);
					
					if(virus == f)	dp[h][j] = dp[h-1][j-1];
				}
			}
			
			else
			{
				if(dp[h-1][j].sz > si)	dp[h][j] = dp[h-1][j];
				if(dp[h][j-1].sz > si)	dp[h][j] = dp[h][j-1];
			}
		}
	
	if(!dp[a][b].sz)	printf("0");
	
	else 	cout<<dp[a][b].s;
}
