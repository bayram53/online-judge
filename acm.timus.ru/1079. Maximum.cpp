# include <stdio.h>

long long n;
long long t[100000];
long long ans[20],m=0;

int main()
{
	t[0]=0;
	t[1]=1;
	
	for(int h=2; h<100000; h++)
	{
		if(h%2==0)
		t[h]=t[h/2];
		
		else
			t[h]=t[h/2]+t[h/2+1];
	}
	
	for(int h=2; h<100000; h++)
	if(t[h]<t[h-1])
		t[h]=t[h-1];
	
	while(1)
	{
		scanf("%lld",&n);
		
		if(n==0)
			break;
			
		ans[m++]=t[n];
	}
	
	for(int h=0; h<m; h++)
		printf("%lld\n",ans[h]);
	
}
