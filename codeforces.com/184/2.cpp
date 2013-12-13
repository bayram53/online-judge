# include <iostream>

using namespace std;

int n;

double d[1009];

double p,q;

int main()
{
	cin>>p>>q;
	
	cin>>n;
	
	for(int h=0; h<n; h++)	cin>>d[h];
	
	double x = d[n-1];
	
	for(int h=n-2; h>-1; h--)
	{
		x = 1.0/x;
		x += d[h];
	}
	
	if(x == p/q)	cout<<"YES";
	else 	cout<<"NO";
}
