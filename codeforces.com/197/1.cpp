# include <stdio.h>
# include <string.h>
# include <algorithm>

using namespace std;

int D[109],d,a;

char c;

int main()
{
	while(1)
	{
		scanf("%d%c",&a,&c);
		D[d++] = a;
		
		if(c == '\n')	break;
	}
	
	sort(D,D+d);
	
	if(d > 0)	printf("%d",D[0]);
	
	for(int h=1; h<d; h++)	printf("+%d",D[h]);
}
