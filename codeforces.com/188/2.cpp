# include <iostream>
# include <stdio.h>
# include <string.h>

using namespace std;

char s[1000009];

char a[] = {"heavy"};
char b[] = {"metal"};

int x[1000009];
int y[1000009];

long long ans;

int main()
{
	scanf("%s",s);
	
	int n = strlen(s);
	
	for(int h=0; h<n-4; h++)
	{
		int k=0,l=0;
		
		for(int j=0; j<5; j++)
		{
			if(s[h+j] != a[j]) k = 1;
			if(s[h+j] != b[j]) l = 1;
		}
		
		if(!k)	x[h] = 1;
		if(!l)	y[h] = 1;
	}
	
	for(int h=1; h<n; h++)
		y[h] += y[h-1];
	
	for(int h=0; h<n; h++)
	{
		if(x[h])
		{
			if(h == 0)	ans += y[n-1];
			else 	ans += y[n-1]-y[h-1];
		}
	}
	
	cout<<ans;
}
