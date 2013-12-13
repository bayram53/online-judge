# include <iostream>
# include <cstdio>

using namespace std;

char a[5][5];
char b[5][5];
char r[5][5];
char pass[17];
int  ps=0;

int main()
{
	for (int i=0 ; i<4 ; i++)
	cin>>a[i];
	
	for (int i=0 ; i<4 ; i++)
	cin>>b[i];
	
	for (int i=0 ; i<4 ; i++)
	{
		for (int i=0 ; i<4 ; i++)
		for (int j=0 ; j<4 ; j++)
		r[i][j]=a[i][j];
		
		for (int i=0 ; i<4 ; i++)
		for (int j=0 ; j<4 ; j++)
		if ( r[i][j]=='X' )
		pass[ps++]=b[i][j];
		
		for (int i=0 ; i<4 ; i++)
		for (int j=0 ; j<4 ; j++)
		a[j][3-i]=r[i][j];
	}
	
	cout<<pass;
	
	return 0;
}
