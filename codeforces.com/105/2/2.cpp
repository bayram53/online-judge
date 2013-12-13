# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;
int vp,vd,t,f,c;
int vp1=0,vd1=0,l=0;
int ans;
int bi=0;
bool j=0;

int main()
{
	scanf("%d %d %d %d %d",&vp,&vd,&t,&f,&c);
	
	while(vp1<c)
	{
		if(vp1==0)
		{
			vp1=vp*t;
			continue;
		}
		
		if(j==1)
		{
			vp1+=(t+f)*vp;
			l=0;
			j=0;
			continue;
		}
		
		if(vp1<=vd1)
		{
			j=1;
			vp1=vd1;
			vd1=0;
			bi++;
			j=1;
			continue;
		}
		
		l++;
		vp1+=vp;
		vd1+=vd;
	}
	
	printf("%d",bi);
	
}
