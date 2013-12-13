# include <stdio.h>
# include <algorithm>

using namespace std;

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)

int n,s,f,m,a,b,l,x1,y1,z1,c,e;

int k[300009];

int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&f);
	
	if(s > f)	e = 1;
	
	for(int h=0; h<m; h++)
	{
		scanf("%d %d %d",&x1,&y1,&z1);
		
		int p = mi(x1-c-1 , abs(f-s));
		
		s += (s < f ? p : -p);
		
		for(int j=0; j<p; j++)	k[l++] = 2;
		
		if(s == f)	break;
		
		if((s < f  &&  y1 <= s+1  &&  z1 >= s)  ||  (s > f  &&  y1 <= s  &&  z1 >= s-1))	k[l++] = 1;
		else 	k[l++] = 2 , s += (s < f ? 1 : -1);
		
		c = x1;
	}
	
	for(int h=mi(s,f); h<ma(s,f); h++)	k[l++] = 2;
	
	for(int h=0; h<l; h++)
	{
		if(k[h] == 2)
		{
			if(e)	printf("L");
			else 	printf("R");
		}
		
		else 	printf("X");
	}
}
