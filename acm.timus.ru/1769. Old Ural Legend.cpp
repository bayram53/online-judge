# include <stdio.h>
# include <string.h>
# include <algorithm>

using namespace std;

int n,m;
char c[100009];
int t[1000009];
bool vis=0;

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=0; h<n; h++)
	{
		int k=0;
		for(int j=h; j<=h+5 && j<n; j++)
		{
			k*=10;
			k+=c[j]-48;
			t[m++]=k;
			
			if(k==1)
				vis=1;
		}
	}
	
	sort(t,t+m);
	int k=1;
	
	while(k<m)
	{
		if(t[k]!=t[k-1]+1 && t[k-1]!=t[k])
			break;
		k++;
	}
	
	if(vis==0)
		printf("1");
	else
		printf("%d",t[k-1]+1);
}
