# include <stdio.h>
# include <algorithm>

using namespace std;

int n;

int D[1009], ans;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&D[h]);
		
		for(int j=0; j<h-1; j++)
		{
			int x1 = D[j], y1 = D[j+1];
			int x2 = D[h-1], y2 = D[h];
			
			if(x1 > y1)	swap(x1, y1);
			if(x2 > y2)	swap(x2, y2);
			
			if((x2 < y1  &&  y2 > y1  &&  x1 < x2)  ||  (x2 < x1  &&  y2 > x1  &&  y1 > y2))	ans = 1;
		}
		
	}
	
	if(ans)	printf("yes");
	else 	printf("no");
}
