# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int d,ans=0;
int k[4];
bool t[100009];

int main()
{
	scanf("%d %d %d %d %d",&k[0],&k[1],&k[2],&k[3],&d);
	
	for(int h=0; h<4; h++)
	for(int j=k[h]; j<=d; j+=k[h])
	t[j]=1;
	
	for(int h=0; h<=d; h++)
	if(t[h]==1)
	ans++;
	
	printf("%d",ans);
}
