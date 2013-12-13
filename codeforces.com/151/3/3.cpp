# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

int n,m=0,x=0,k;
bool vis[50000009];
struct mal
{
	int b,c;
	bool v[109];
};
int t[109];
mal a[1000];

int main()
{
	scanf("%d %d",&n,&k);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	for(int h=0; h<n; h++)
	{
		if(m==k)
			return 0;
		
		if(vis[t[h]]==0)
		{
			a[m].v[h]=1;
			a[m++].b=t[h];
			printf("1 %d\n",t[h]);
			vis[t[h]]=1;
			a[m-1].c=1;
		}
		
		x=0;
		
		while(x<m)
		{
			if(m==k)
			return 0;
			
			if(vis[a[x].b+t[h]]==0 && a[x].v[h]==0)
			{
				printf("%d %d ",a[x].c+1,t[h]);
				
				for(int h1=0; h1<n; h1++)
				{
					if(a[x].v[h1]==1)
					printf("%d ",t[h1]);
					
					a[m].v[h1]=a[x].v[h1];
				}
				
				a[m].c=a[x].c+1;
				a[m].v[h]=1;
				a[m++].b=a[x].b+t[h];
				vis[a[x].b+t[h]]=1;
				printf("\n");
			}
			x++;
		}
	}	
}
