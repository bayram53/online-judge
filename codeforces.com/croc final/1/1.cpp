# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

int n,a,b,x;
int t[109],m=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
			
		if(b==2 && a<0)
		t[m++]=x,b=0,x=0;
		
		x++;
		
		if(a<0)
			b++;
	}
	
	if(m==0 && b==0)
		t[m++]=x;
	
	else if(b!=0)
		t[m++]=x;
		
	else
		t[m-1]+=x;
	
	printf("%d\n",m);
	
	for(int h=0; h<m; h++)
		printf("%d ",t[h]);
}
