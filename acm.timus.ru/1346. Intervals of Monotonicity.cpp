# include <stdio.h>

int a,b,n,d,ans;

int t[10],t1;

int sign(int a)
{
	if(a < 0)	return 0;
	if(a > 0)	return 1;
	return 2;
}

int main()
{
	scanf("%d %d %d",&a,&b,&t[t1++]);
	
	for(int h=a; h<b; h++)
	{
		scanf("%d",&d);
		
		if(t1 == 1)	t[t1++] = d;
		
		else
		{
			if(t[1] == d)	continue;
			
			if(sign(t[0]-t[1]) + sign(t[1]-d) == 1)	t1 = 1 , t[0] = d , ans++;
			else t[0] = t[1] , t[1] = d;
		}
		
		//for(int j=0; j<t1; j++)	printf("%d ",t[j]); printf("\n");
	}
	
	printf("%d\n",ans+1);
}
