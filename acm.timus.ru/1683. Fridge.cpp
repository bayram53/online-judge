# include <stdio.h>

int n,m;
int d[31];

int main()
{
	scanf("%d",&n);
	
	while(n != 1)
	{
		bool p = (n % 2 == 0);
		
		d[m++] = n/2;
		
		n /= 2;
		
		if(!p)
			n++;
	}
	
	printf("%d\n",m);
	
	for(int h=0; h<m; h++)
		printf("%d ",d[h]);
}
