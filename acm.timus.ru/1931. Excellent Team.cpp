# include <stdio.h>

int n,a,pos=0,ans;
int t[100009];
int s[100009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	a=t[0];
	
	for(int h=1; h<n; h++)
	{
		s[h]++;
		s[pos]++;
		
		if(a>t[h])
			pos=h,a=t[h];
	}
	
	ans=-1;
	
	for(int h=0; h<n; h++)
	if(ans<s[h])
	{
		ans=s[h];
		pos=h;
	}
		
	printf("%d",pos+1);
}
