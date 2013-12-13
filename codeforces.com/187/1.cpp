# include <stdio.h>

int n,a,b,ans;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&a,&b);
		
		if(a == b)	ans++;
	}
	
	printf("%d",ans);
}
