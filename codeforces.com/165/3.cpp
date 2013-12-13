# include <stdio.h>
# include <math.h>
# include <iostream>
# include <string.h>
# include <algorithm>
# include <stdlib.h>

using namespace std;

struct mal
{
	int a,b;
};

mal t[100009];
long long n,a;
long long b;

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a == n.a)
		return m.b - n.b;
	return m.a - n.a;
}

int main()
{
	cin>>n;
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&t[h].a,&t[h].b);
	
	qsort(t , n , sizeof(mal) , so);
	
	a = t[0].a;
	b = t[0].b;
	
	for(int j=1; j<n; j++)
	{
		if(a + 15 <t[j].a)
			{a = t[j].a; b = t[j].b; continue;}
		
		double f = pow(4.0 , (t[j].a - a) * 1.0);
		double s1 = t[j].b;
		double s2 = b;
		
		if( s2 / f < s1)
			{a = t[j].a; b = t[j].b; continue;}
		
		a = t[j].a;
		b = (long long) s2/f;
		
		long long e = s2/f;
		
		if(0.0 < s2/f - (double)e)
			b++;
	}
	
	
	double q = b;
	
	while(1)
	{
		a++;
		
		if(q / 4.0 <= 1.0)
			break;
		q/= 4.0;
	}
	
	cout<<a;
}
