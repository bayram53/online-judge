# include <stdio.h>
# define mi(x,y) (x<y ? x : y)

int n;
int t[2009];
int a[2009][2];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	for(int h=0; h<n; h++)
	{
		int x=0,y=0;
		
		for(int j=0; j<h; j++)
			if(t[h]>t[j])
				x++;
		
		for(int j=h+1; j<n; j++)
			if(t[h]<t[j])
				y++;
		
		a[t[h]][0]=h+1-x;
		a[t[h]][1]=h+1+y;
	}
	
	for(int h=1; h<=n; h++)
		printf("%d %d\n",a[h][0],a[h][1]);
}
