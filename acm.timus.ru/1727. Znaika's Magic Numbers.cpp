# include <stdio.h>

int n,m,p=9999;
int ans[100009];

int main()
{
	scanf("%d",&n);
	
	while(n!=0 && p!=0)
	{
		int o=p,k=0;
		
		while(o!=0)
		{
			k+=o%10;
			o/=10;
		}
		
		if(n-k>=0)
			n-=k,ans[m++]=p;
		
		p--;
	}
	
	/*if(n!=0)
	{
		printf("-1");
		return 0;
	}*/
	
	printf("%d\n",m);
	
	for(int h=0; h<m; h++)
		printf("%d ",ans[h]);
}
