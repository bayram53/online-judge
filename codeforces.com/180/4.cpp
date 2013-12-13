# include <stdio.h>
# include <algorithm>

using namespace std;

int k,n,m,c,d;
int a[100009],b[100009];

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
	for(int h=0; h<n; h++)	scanf("%d",&a[h]);
	for(int h=0; h<m; h++)	scanf("%d",&b[h]);
	
	sort(a,a+n);
	sort(b,b+m);
	
	int x=n-1,y=m-1;
	
	while(1)
	{
		if(x == -1  &&  y == -1)
			break;
		
		if(x == -1)	d++,y--;
		
		else if(y == -1) c++,x--;
		
		else
		{
			if(a[x] == b[y]) x--,y--;
			else if(b[y] < a[x])	x--,c++;
			else 	y--,d++;
		}
		
		if(c > d)
		{
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
}
