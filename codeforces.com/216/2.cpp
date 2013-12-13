# include <stdio.h>

int n, k, l, r, sall, sk;
int D[10009];

int main()
{
	scanf("%d %d %d %d %d %d",&n,&k,&l,&r,&sall,&sk);
	
	for(int h=k; h<n; h++)	D[h] = l;
	
	sall -= ((n-k)*l + sk);
	
	for(int h=0; h<k; h++)	D[h] = sk/k;
	
	sk %= k;
	
	for(int h=0; h<sk; h++)	D[h]++;
	
	int a = n-k;
	
	if(a)
	{
		for(int h=k; h<n; h++)	D[h] += sall/a;
	
		sall %= a;
	}
	
	for(int h=k; h<k+sall; h++)	D[h]++;
	
	for(int h=0; h<n; h++)	printf("%d ",D[h]);
}
///5 5 1 3 5 5 
