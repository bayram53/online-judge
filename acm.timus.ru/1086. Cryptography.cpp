# include <stdio.h>
# include <math.h>

bool pr[1000009];
int ans[79000],a=1;
int t[1600],n;

int main()
{
	for(int h=2; h<1001; h++)
	{
		for(int j=h*h; j<1000002; j+=h)
		pr[j]=1;
		
	}
	
	for(int h=1; h<1000002; h++)
		if(pr[h]==0)
			ans[a++]=h;
			
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	printf("%d",ans[t[0]+1]);
		
	for(int h=1; h<n; h++)
		printf("\n%d",ans[t[h]+1]);
}
