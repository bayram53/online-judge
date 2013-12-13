# include <stdio.h>
# include <limits.h>
# define inf LLONG_MAX
# define mi(x,y) (x<y ? x : y)

int n,a,b,g;
char c[100];
long long t[39][39];
long long ans=inf;

int main()
{
	for(int h=0; h<39; h++)
		for(int j=0; j<39; j++)
			t[h][j]=inf;
	
	scanf("%d\n",&n);
	
	if(n==0)
		{printf("0");return 0;}
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&g);
		
		for(int j=0; j<g; j++)
		{
			while(1){
			scanf("%d",&a);
			
			if(a==0)
				break;
			
			scanf("%d",&b);
			
			if(h==0)
				t[h][j+1]=b;
			
			else
				t[h][j+1]=mi(t[h][j+1],t[h-1][a]+b);}
		}
		
		if(n!=1 && h!=n-1)
			scanf("%s",c);
	}
	
	for(int h=0; h<39; h++)
		if(ans>t[n-1][h])
			ans=t[n-1][h];
	
	
	printf("%lld",ans);
}
