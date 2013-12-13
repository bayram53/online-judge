# include <iostream>

using namespace std;

long long a,b;

int main()
{
	cin>>a>>b;
	
	long long k = a/2;
	
	if(a%2)	k++;
	
	if(b > k)
	{
		b -= a/2;
		if(a%2 != 0)	b--;
		cout<<b*2;
	}
	
	else 	cout<<b*2-1;
}
