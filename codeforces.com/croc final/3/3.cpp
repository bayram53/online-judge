# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,a,b,ans=10000000,o=1000000;
int k[100009];
int t[100009],m=0;
int g[100009];

int main()
{
	scanf("%d %d",&n,&b);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		if(h==0 || t[m-1]!=a)
			t[m++]=a;
	}
	
	for(int h=1; h<m-1; h++)
		if(t[h-1]==t[h+1])
			k[t[h]]++;
	
	for(int h=0; h<m; h++)
		g[t[h]]++;
		
			
	for(int h=0; h<m; h++)	
		if((ans>m-k[t[h]]-g[t[h]]-1) || (ans==m-k[t[h]]-g[t[h]]-1 && o>t[h]))
			ans=m-k[t[h]]-g[t[h]]-1,o=t[h];
			
	printf("%d",o);
}
