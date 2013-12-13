# include <stdio.h>
# include <algorithm>

using namespace std;

int n,a,b;
int x,y;

int main()
{
	for(int h=0; h<5; h++)
		for(int j=0; j<5; j++)
		{
			scanf("%d",&a);
			
			if(a==1)
				x=h+1,y=j+1;
		}
	printf("%d",abs(x-3)+abs(y-3));
}
