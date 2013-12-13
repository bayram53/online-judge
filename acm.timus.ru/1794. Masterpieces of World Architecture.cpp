# include <stdio.h>

int n,a,ans,m;
int t[100009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		t[((h+1)-a+n)%n+1]++;
	}
	
	for(int h=0; h<=n; h++)
		if(ans<t[h])
			ans=t[h],m=h;
		
	printf("%d\n",m);
}
