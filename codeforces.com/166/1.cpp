# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>
# include <vector>
# include <limits.h>

int n;
int v[99];

int main()
{
	scanf("%d",&n);
	
	for(int h=n+1; h<90001; h++)
		{
			int ans=0;
			memset(v,0,sizeof(v));
			
			v[h%10] = 1;
			v[h/1000] =1;
			v[(h/100)%10]= 1;
			v[(h%100)/10] =1;
			
			for(int j=0; j<10;j++)
				ans += v[j];
			
			if(ans == 4)
			{
				printf("%d",h);
				return 0;
			}
		}
	
}
