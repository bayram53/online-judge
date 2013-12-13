# include <stdio.h>
# include <algorithm>

using namespace std;

int a,b,an,z,mx,x;

int c[109];
int v[109];
int p[109];
int u[109];

int main()
{
	scanf("%d",&a);
	
	for(int i=0;i<a;i++)
	{
		scanf("%d",&c[i]);
		
		if(c[i]==100)
		{p[an]=c[i];an++;}
		if(c[i]==0)
		{p[an]=c[i];an++;}
		if(c[i]<10 && c[i]>0 && z==0)
		{p[an]=c[i];an++;z=1;}
		if(c[i]<100 && c[i]>9 && c[i]%10==0 && x==0)
		{p[an]=c[i];an++;x=1;}
	}if(an==0)p[0]=c[0],an=1;printf("%d\n",an);for(int i=0;i<an;i++)printf("%d ",p[i]);getchar();getchar();
}
