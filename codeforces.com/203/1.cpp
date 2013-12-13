# include <stdio.h>

int a,b,mn,mx,wm;

int main()
{
	scanf("%d %d",&a,&b);
	
	for(int h=0; h<a; h++)
	{
		int c;
		
		scanf("%d",&c);
		
		if(!mn  ||  c < mn)	mn = c;
		if(mx < c)	mx = c;
	}
	
	for(int h=0; h<b; h++)
	{
		int c;
		
		scanf("%d",&c);
		
		if(!wm  ||  c < wm)	wm = c;
	}
	
	if(mx < 2*mn)	mx = 2*mn;
	
	if(mx >= wm)	printf("-1");
	else 	printf("%d\n",mx);
}
