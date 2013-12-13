# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <ctype.h>

using namespace std;

int month[]={31,28,31,30,31,30,31,31,30,31,30,31,0};
char c[100009];
int n,ans=-1;
int t[39][175][100];

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	int a,b,c1;
	for(int h=0; h<=n-10; h++)
	if(c[h+2]=='-' && c[h+5]=='-' && isdigit(c[h]) && isdigit(c[h+1]) && isdigit(c[h+3]) && isdigit(c[h+4]) && isdigit(c[h+6])
	 && isdigit(c[h+7]) && isdigit(c[h+8]) && isdigit(c[h+9]))
	{
		int x,y,z;
		x=(c[h]-48)*10+c[h+1]-48;
		y=(c[h+3]-48)*10+c[h+4]-48;
		z=(c[h+6]-48)*1000+(c[h+7]-48)*100+(c[h+8]-48)*10+(c[h+9]-48);
		
		if((z>2012 && z<2016) && (y>0 && y<13) && (x>0 && x<=month[y-1]))
		{
			t[x][y][z-2012]++;
			if(ans<t[x][y][z-2012])
				a=x,b=y,c1=z,ans=t[x][y][z-2012];
		}
		
		
	}
	
	if(a<10)
		printf("0%d-",a);
	else
		printf("%d-",a);
		
	if(b<10)
		printf("0%d-",b);
	else
		printf("%d-",b);
		
	printf("%d",c1);
}
