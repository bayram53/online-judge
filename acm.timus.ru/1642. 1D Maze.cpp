# include <stdio.h>
# include <algorithm>

using namespace std;

int n,k,l;
int a=-1,b=-1;
int vis1[100009],vis2[100009];
bool p[100009];

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&l) , p[l+10000]=1;
	
	int pos = 0, ti = 0, yon = 0;
	
	while(vis1[pos+10000] < 3 &&   abs(pos) < 1009)
	{
		vis1[pos+10000]++;
		
		if(pos == k)
			{a=ti; break;}
		
		if(p[pos + 10000] == 1)
			yon++;
		
		if(yon % 2 == 0)
			pos++;
		else
			pos--;
		
		ti++;
	}
	
	yon = 1;
	pos = 0;
	ti = 0;
	
	while(vis2[pos+10000] < 3  &&  abs(pos) < 1009)
	{
		vis2[pos+10000]++;
		
		if(pos == k)
			{b=ti; break;}
		
		if(p[pos + 10000] == 1)
			yon++;
		
		if(yon % 2 == 0)
			pos++;
		else
			pos--;
		
		ti++;
	}
	
	if(a == -1  ||  b == -1)
		printf("Impossible");
	else
		printf("%d %d",a,b);
}
