# include <stdio.h>

int n,m,ans,l;

int main()
{
	scanf("%d %d",&n,&m);
	for(int h=0; h<m; h++)
	{ scanf("%d",&l); ans+=l; ans-=n; if(ans<0)ans=0; }
	
	printf("%d",ans);
}
