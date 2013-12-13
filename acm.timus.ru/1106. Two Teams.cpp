# include <stdio.h>

int n,a;
bool vis[109][109];
int group[109],san=1;
bool m[109];
int k[109],k1=0,k2=0;
int ans;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	while(1)
	{
		
		scanf("%d",&a);
		
		if(a==0)
			break;
		
		vis[h][a-1]=1;
	}
	group[0]=1;
	k[k1++]=0;
	m[0]=1;
	while(san<n)
	{
		if(k2==k1)
		{
			for(int h=0; h<n; h++)
				if(m[h]==0)
				{k[k1++]=h; m[h]=1;  group[h]=1; san++; break;}
				
			continue;
		}
		
		for(int h=0; h<n; h++)
		if(vis[k[k2]][h]==1 && m[h]==0)
		{
			m[h]=1;
			k[k1++]=h;
			
			if(group[k[k2]]==1)
				group[h]=2;
			
			else
				group[h]=1;
			
			san++;
		}
		
		k2++;
	}
	
	for(int h=0; h<n; h++)
	if(group[h]==1)
	ans++;
	
	printf("%d\n",ans);
	
	for(int h=0; h<n; h++)
	if(group[h]==1)
	printf("%d ",h+1);
}
