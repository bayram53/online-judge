# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,l=1,ans=1;
int t[4009];
int b[4009][4009];
int p[1000009];
int k[4009];
int s[4009][4009];

int tap(int x,int y)
{
	if(s[x][y]!=-1)
		return s[x][y];
	
	if(b[p[t[x]]][y]==-1)
		return 0;
	
	return s[x][y]=1+tap(y,b[p[t[x]]][y]);
}

int main()
{
	for(int h=0; h<4009; h++)
		for(int j=0; j<4009; j++)
			b[h][j]=-1,s[h][j]=-1;
	
	scanf("%d",&n);

	for(int h=0; h<n; h++)
		scanf("%d",&t[h]),k[h]=t[h];
	
	sort(k,k+n);
	
	p[k[0]]=0;
	
	for(int h=1; h<n; h++)
		if(k[h-1]!=k[h])
			p[k[h]]=l++;
			
	p[k[n-1]]=l;
	
	for(int h=0; h<n; h++)
		for(int j=h+1; j<n; j++)
			b[p[t[h]]][j]=max(b[p[t[h]]][j],h);
			
	for(int h=0; h<n; h++)
		for(int j=h+1; j<n; j++)
			if(h!=j)
				ans=max(ans,tap(h,j)+1);
				
	printf("%d",ans);
}	
