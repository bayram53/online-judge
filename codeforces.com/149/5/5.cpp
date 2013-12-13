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
int a,b;
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



int main()
{
	
	
}

//qsort(t,n,sizeof(students),function);
