# include <stdio.h>

int n, gyr, m;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<m; j++)
		{
			int a;
			scanf("%d",&a);
			if(a  &&  (!h  ||  !j  ||  h == n-1   ||  j == m-1))	gyr = 1;
		}
	
	if(gyr)	printf("2");
	else 	printf("4");
}
