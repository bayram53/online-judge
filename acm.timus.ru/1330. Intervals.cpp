# include <stdio.h>

int n,a,b;
int t[10009];

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=n; h++)
		scanf("%d",&t[h]),t[h]+=t[h-1];
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&a,&b),printf("%d\n",t[b]-t[a-1]);
}
