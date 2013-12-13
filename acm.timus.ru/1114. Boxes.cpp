# include <iostream>

using namespace std;

long long n,a,b;

unsigned long long sayla(int x,int y)
{
	long long p=1;
	for(int h=x; h>x-y; h--)
		p*=h;
	
	for(int h=2; h<=y; h++)
		p/=h;
	return p;
}

unsigned long long tap(int x,int y)
{
	if(x==1)
		return 1;
	
	else
	{
		unsigned long long k=0;
		
		for(int h=1; h<=y; h++)
		{
			if(y-h-x+1<0)
				break;
			k+=tap(x-1,y-h);
		}
		
		return k;
	}
}

int main()
{
	cin>>n>>a>>b;
	unsigned long long ak=1,gok=1;
	
	int d=a;
	if(a<b)
		d=b;
	
	for(int h=1; h<=d; h++)
		for(int j=1; j<=n && h>=j; j++)
		{
			unsigned long long mal=tap(j,h)*sayla(n,j);
			if(a>=h)
				ak+=mal;
			if(b>=h)
				gok+=mal;
		}
	
	cout<<ak*gok;
}
