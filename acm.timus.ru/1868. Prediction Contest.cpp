# include <stdio.h>
# include <string.h>

char a[39],b[39];
int n,k;
char c[15][39];
int x,y;

int main()
{
	for(int h=1; h<=12; h++)
		scanf("%s",c[h]);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		int d=0;
		
		scanf("%d",&k);
		
		for(int j=0; j<k; j++)
		{
			
			
			scanf("%s : %s",a,b);
			
			if(b[0] == 'g')
			{
				bool p = 0;
				
				for(int h=1; h<5; h++)
					if(strcmp(c[h] , a) == 0)
						p = 1;
				
				if(p == 1)
					d++;
			}
			
			if(b[0] == 's')
			{
				bool p = 0;
				
				for(int h=5; h<9; h++)
					if(strcmp(c[h] , a) == 0)
						p = 1;
				
				if(p == 1)
					d++;
			}
			
			if(b[0] == 'b')
			{
				bool p = 0;
				
				for(int h=9; h<13; h++)
					if(strcmp(c[h] , a) == 0)
						p = 1;
				
				if(p == 1)
					d++;
			}
		}
		
		if(d == x)
			y++;
		if(x < d)
			y=1 , x=d;
	}
	
	printf("%d",y*5);
}
