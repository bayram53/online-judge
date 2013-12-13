# include<iostream>
# include <algorithm>

using namespace std;

int x,y;

int main ()
{

	cin>>x>>y;
	if((x % 2) != (y % 2)  &&  x>0  &&  y>0)
		swap(x,y);
	
	cout<<x<<" "<<y<<endl;
}
