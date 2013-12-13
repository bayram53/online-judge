# include <stdio.h>

int n;
int t[3009];

void tap(int x,int y)
{
	if(x==0)
		return ;
	
	//for(int h=y; h>y-x; h--)
		//printf("%d ",t[h]);
	
	//printf("\n");
	
	int p=0;
	
	if(x==1)
		{printf("%d ",t[y]);return ;}
		
	for(int h=y-1; h>y-x; h--)
	{
		if(t[y]>t[h])
			break;
		p++;
	}
	
	tap(p,y-1);
	
	tap(x-1-p,y-1-p);
	
	printf("%d ",t[y]);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
	
	tap(n,n-1);
}
