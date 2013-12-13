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
	
	if(b>9)
	{
		
		for(int h=0; h<10; h++)
		{
			int p=a;
			
			if((p*10+h)%b==0)
			{
				cout<<p*10+h;
				
				for(int h=1; h<n; h++)
					cout<<0;
				return 0;
			}
		}
		
		cout<<-1;
		
		return 0;
	}
	a*=10;
	a+=b-(a%b);
	
	cout<<a;
	
	for(int h=1; h<n; h++)
		cout<<0;
}
