# include <stdio.h>

int n,a,ma=-1;
int as=-1;
int t[25009];
int g[25009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		t[a]++;
		
		if(ma<a)
			ma=a;
	}
	
	g[t[ma]]++;
	
	for(int h=ma-1; h>0; h--)
	{
		t[h]+=t[h+1];
		g[t[h]]++;
	}
	
	for(int h=t[1]-1; h>0; h--)
		g[h]+=g[h+1];
	
	for(int h=1; h<=t[1]; h++)
	{
		if(t[1]==h)
			printf("%d",g[h]);
		
		else
			printf("%d ",g[h]);
	}
	
	
}
