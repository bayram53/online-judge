# include <iostream>
# include <math.h>
# include <algorithm>

using namespace std;

typedef long long llint;

llint n,t[1000009],b,a,k;

long double k1;

llint b_s(llint l,llint r)
{
	long double x1 = (long double)l;
	long double y1 = (long double)r;
	
	if(r-l < 2)
	{
		if((long double)(2*a) == x1*(x1-1+k1))	return l;
		if((long double)(2*a) == y1*(y1-1+k1))	return r;
		return 0;
	}
	
	long double x = (long double)((l+r)/2);
	
	if(x*(x-1+k1) < (long double)(2*a))	return b_s((l+r)/2,r);
	
	return b_s(l,(l+r)/2);
}

int main()
{
	cin>>a;
	
	llint o = (llint)sqrt(a*2.0);
	
	if(a*2 == o*(o+1)  &&  o%2 == 0)	t[b++] = o+1;
	
	for(llint h=1; h<61; h++)
	{
		k = 0;
		for(llint j=0; j<h; j++) k += (llint)pow(2.0,j*1.0);
		
		k *= 2;
		
		k1 = (long double)k;
		
		//if(k > a)	break;
		
		if(b_s(1,10000000000)%2 == 1)	t[b++] = b_s(1,10000000000)*(llint)pow(2.0,h*1.0);
	}
	
	sort(t , t+b);
	
	if(!b)	cout<<-1;
	else 	for(int h=0; h<b; h++)if(!h  ||  t[h-1] != t[h])	cout<<t[h]<<endl;
}
