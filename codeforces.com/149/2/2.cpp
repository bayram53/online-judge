# include <stdio.h>
# include <stdlib.h>
# include <algorithm>
# include <string.h>

using namespace std;

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int lcm(int a,int b)
{
return a/gcd(a,b)*b;
}

struct students
{
int a,b,c;
};

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int n;
students t[100009];
int a,b,c1=-1;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&t[h].a,&t[h].b);
		if(t[h].b>c1)
		c1=t[h].b;
		
		t[h].c=h+1;
	}
	
	qsort(t,n,sizeof(students),function);
	
	for(int h=0; h<n; h++)
	if(t[h].a==t[0].a && c1==t[h].b)
	{printf("%d",t[h].c); return 0;}
	
		printf("-1");
}

//qsort(t,n,sizeof(students),function);
