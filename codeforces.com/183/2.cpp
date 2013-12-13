# include <stdio.h>
# include <algorithm>

using namespace std;

int mo[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int y1,m1,d1;
int y2,m2,d2;
int ans;

int leap(int x)
{
	if((x%400==0)||((x%4==0)&&(!(x%100==0))))	return 1;
	return 0;
}

int den(int x1,int y1,int z1,int x2,int y2,int z2)
{
	if(x1 < x2  ||  (x1 == x2  &&  y1 < y2)  ||  (x1 == x2  &&  y1 == y2  &&  z1 < z2))	return 1;
	if(x1 == x2  &&  y1 == y2  &&  z1 == z2)	return 0;
	return 2;
}

void denle()
{
	if(leap(y1)  &&  m1 == 1)
	{
		if(d1 == 30)	d1 = 1 , m1++;
		return ;
	}
	
	if(d1>mo[m1])	m1++ , d1 = 1;
	if(m1 == 12) m1 = 0 , y1++;
	
}

int main()
{
	scanf("%d:%d:%d\n%d:%d:%d",&y1,&m1,&d1,&y2,&m2,&d2);
	m1--;m2--;
	if(den(y1,m1,d1,y2,m2,d2) == 2)	swap(m1,m2) , swap(y1,y2) , swap(d1,d2);
	
	while(1)
	{
		denle();
		
		if(den(y1,m1,d1,y2,m2,d2) != 1)	break;
		ans++;
		d1++;
	}
	
	printf("%d\n",ans);
}
