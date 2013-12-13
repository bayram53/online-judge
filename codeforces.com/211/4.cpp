# include <stdio.h>

int n, po[109];

int main()
{
	po[0] = 1;
	
	for(int h=1; h<30; h++)	po[h] = po[h-1]*2;
	
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)	scanf("");
}
