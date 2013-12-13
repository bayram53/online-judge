# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

double y1,y2,yw,xb,yb,r;
double p,b;
int main()
{
	scanf("%lf %lf %lf %lf %lf %lf",&y1,&y2,&yw,&xb,&yb,&r);
	
	p=yw-yb-r;
	b=(y1+y2)/2;
	
	if(y2-y1<=2*r)
	{
		printf("-1");
		return 0;
	}
	
	printf("%lf",(p*xb-b*xb)/(2*p-b));
}
