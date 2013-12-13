# include <iostream>
# include <algorithm>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <math.h>

using namespace std;

long long  n,a,b,p;

int main()
{
	cin>>a>>b>>n;
	
	int i=0;
	p=a;
	
	while(p!=0)
	{
		i++;
		p/=10;
	}
	
	p=a;
	
	for(int h=1; h<=5; h++)
	{
		p*=10;
		if(int(pow(10,h))>b-(p%b))
		{
			p+=b-(p%b);
			break;
		}
	}
	
	int k=p,o=0;
	
	while(k!=0)
	{
		o++;
		k/=10;
	}
	
	if(o-i>n)
		cout<<-1;
		
	else
	{
		cout<<p;
		for(int h=0; h<n-o+i; h++)
			cout<<0;
	}
}
