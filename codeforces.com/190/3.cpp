# include <stdio.h>
# include <string.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

using namespace std;

int a,b,x,y;

char s[109];

int main()
{
	scanf("%d %d %s",&a,&b,s);
	
	int n = strlen(s);
	
	if(!a  &&  !b){printf("Yes");return 0;}
	
	for(int h=0; h<n; h++)
	{
		if(s[h] == 'U')	y++;
		if(s[h] == 'D') y--;
		if(s[h] == 'L')	x--;
		if(s[h] == 'R')	x++;
		if(x == a  &&  y == b){printf("Yes");return 0;}
	}
	
	int x1 = 0; if(x)	x1 = a/x;
	int y1 = 0; if(y)	y1 = b/y;
	int k = mi(ma(0,x1),ma(0,y1));
	
	if(!x1)	k = y1;	if(!y1)	k = x1;
	
	k = ma(0 , k-100);
	
	x *= k;
	y *= k;
	
	if(x == a  &&  y == b){printf("Yes");return 0;}
	
	for(int j=0; j<200; j++)
		for(int h=0; h<n; h++)
		{
			if(s[h] == 'U')	y++;
			if(s[h] == 'D') y--;
			if(s[h] == 'L')	x--;
			if(s[h] == 'R')	x++;
			if(x == a  &&  y == b){printf("Yes");return 0;}
		}
	
	printf("No");
}
