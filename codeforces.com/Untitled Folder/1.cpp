# include <stdio.h>

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int n;

int d[100009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&d[h]);
	
	int p = d[0];
	
	for(int h=1; h<n; h++)	p = gcd(p,d[h]);
	
	for(int h=0; h<n; h++)	if(p == d[h]){printf("%d",d[h]);	return 0;}
	
	printf("-1");
}
