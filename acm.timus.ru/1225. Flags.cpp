# include <stdio.h>

long long n;
long long t[3][3],g[3][3];
long long ans=0;

int main()
{
	scanf("%lld",&n);
	
	if(n==2 || n==1)
	{
		printf("2");
		return 0;
	}
	
	t[0][1]=1;
	t[1][0]=1;
	
	for(int h=3; h<=n; h++)
	{
		for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				g[j][k]=t[j][k];
		
		t[0][1]=(g[1][0]+g[2][0]);
		t[1][0]=(g[0][1]+g[2][1]);
		t[2][0]=g[1][0];
		t[2][1]=g[0][1];
	}
	
	for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				ans+=t[j][k];
	
	printf("%lld",ans);
}
