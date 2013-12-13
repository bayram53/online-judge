# include <stdio.h>

int n,a,m;
bool v[110][109];
int t[109];

int main()
{
	scanf("%d",&n);
	
	m=n;
	
	for(int h=1; h<=n; h++)
	{
		a=1;
		while(a)
		{
			scanf("%d",&a);
			
			v[h][a]=1;
			t[a]++;
		}
	}
	
	while(m!=0)
	{
		for(int h=1; h<=n; h++)
			if(t[h]==0)
			{
				printf("%d ",h);
			
				for(int j=1; j<=n; j++)
					if(v[h][j]==1)
						t[j]--;
					m--;		
					
					t[h]=-1;
			}
	}
}
