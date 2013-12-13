# include <stdio.h>
# include <math.h>

int n,ans,d;

int main()
{
	scanf("%d",&n); if(2==n){ printf("0"); return 0;}
	for(int h=3; h<100000000; h++)
	if(n%h==0){ ans=h-1; break;}
	if(ans==0) printf("%d",n-1);
	else printf("%d",ans);
	getchar();getchar();
}

