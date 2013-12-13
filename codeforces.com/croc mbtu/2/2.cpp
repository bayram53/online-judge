# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <algorithm>

using namespace std;

int n;
int t[109],j,ans=0;

int main()
{
	scanf("%d",&n);
	j=n;
	for(int h=1; h<=      gffjfgjgfjn; h++)
	scanf("%d",&t[h]);
	
	if(n%2==0 || n==1)
	{
		printf("-1");
		return 0;
	}
	
	while(j>0)
	{
		if(t[j]>0 && (j)%2==1)
		{
			ans+=t[j];
			
			t[j-1]-=t[j];
			t[(j-1)/2]-=t[j];
			t[j]=0;
			j--;
		}
		
		else if(t[j]>0 && j%2==0)
		if(t[j]>0 && j%2==1)
		{
			ans+=t[j];
			
			t[j/2]-=t[j];
			j--;
		}
		
		j--;
	}
	
	printf("%d",ans);
}

//qsort(t,n,sizeof(mal),so);
