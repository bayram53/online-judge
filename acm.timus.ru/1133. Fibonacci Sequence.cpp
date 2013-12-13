# include <stdio.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

using namespace std;

typedef long long llint;

int a,fa,b,fb,n;

llint F[20009];

llint d[10][3];

int main()
{
	scanf("%d %d %d %d %d",&a,&fa,&b,&fb,&n);
	
	if(a > b)	swap(a,b) , swap(fa,fb);
	
	llint k = mi(a,mi(b,n));
	
	a -= k;	b -= k;	n -= k;
	
	F[a] = (llint)fa;
	
	F[b] = (llint)fb;
	
	d[a%3][0] = 1;
	d[(a+1)%3][1] = 1;
	
	for(int h=a+2; h<=b; h++)
	{
		d[h%3][0] = d[(h+2)%3][0] + d[(h+1)%3][0];
		d[h%3][1] = d[(h+2)%3][1] + d[(h+1)%3][1];
		
		if(h == b  &&  d[h%3][1])
		{
			double x = d[h%3][0]*1.0 , y = d[h%3][1]*1.0;
			double b1 = fa*1.0 , c1 = fb*1.0 , a1;
			a1 = (c1-b1*x)/y;
			F[a+1] = (llint)a1;
			//F[a+1] = (fb-fa*d[h%3][0])/d[h%3][1];
		}
	}
	
	for(llint h=a+1; h>ma(1,n+1); h--)
		F[h-2] = F[h]-F[h-1];
	
	for(llint h=a+2; h<=n; h++)	F[h] = F[h-1]+F[h-2];
	
	printf("%lld\n",F[n]);
	
	//for(int h=0; h<=n; h++)	printf("%d , ",F[h]);
}
//46 1836311903 -46 -1836311903 45
