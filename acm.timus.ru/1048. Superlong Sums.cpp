# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int n,a,b,c;
int k[1000009][2];
vector <int> t;

int main()
{
	scanf("%d",&n);
	
	for(int j=0; j<n; j++)
		scanf("%d %d",&k[j][0],&k[j][1]);
	
	for(int h=n-1; h>-1; h--)
	{
		t.push_back((k[h][0]+k[h][1]+c)%10);
		c=(k[h][0]+k[h][1]+c)/10;
	}
	
	if(c!=0)
		t.push_back(c);
	
	reverse(t.begin(),t.end());
	
	for(int h=0; h<(int)t.size(); h++)
		printf("%d",t[h]);
}
