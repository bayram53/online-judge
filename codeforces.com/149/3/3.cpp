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
	
	if(m.a==n.a && m.b==n.b)
	return m.c-n.c;
	else if(m.b==n.b)
	return m.b-n.b;
	else
	return m.a-m.b;
}

students t[100009];
int n;

int main()
{
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	scanf("%d %d %d",&t[h].a,&t[h].b,&t[h].c);
	
	qsort(t,n,sizeof(students),function);
	
	
	
	
	
}

//qsort(t,n,sizeof(students),function);
