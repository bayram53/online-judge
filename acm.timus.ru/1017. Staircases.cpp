# include <stdio.h>

int n;
long long t[9009],ans=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=1; h<=500; h++)
	{
		for(int j=500; j>0; j--)
			if(t[j]!=0)
				t[h+j]+=t[j];
		
		t[h]+=1;		
	}
	
	printf("%lld",t[n]-1);
}
