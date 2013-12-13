# include <stdio.h>
# include <string.h>

char word1[100000];
int h,w,n,s=0,ans=0,a;
int sizew[100080];

int main()
{
	scanf("%d %d %d",&h,&w,&n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%s",word1);
		sizew[i]=strlen(word1);
	}
	
	for(int i=0; i<2*n-1; i++)
	{
		if(i%2==1)
		{
			s++;
			continue;
		}
			
		else if(s+sizew[a]>w)
		{
			ans++;
			s=0;
		}
	
			s+=sizew[a];
		
		a++;
	}
	ans++;
	if(ans%h==0)
		printf("%d",ans/h);
		
	else
		printf("%d",ans/h+1);
	
}
