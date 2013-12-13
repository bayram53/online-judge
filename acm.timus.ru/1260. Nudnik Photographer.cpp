# include <stdio.h>

long long n,ans=0;
long long t[100];

long long tapmak(long long y)
{
	if(y==1 || y==2) return 1;
	
	else if(y==3) return 2;
	
	else if(y==4) return 4;
	
	else if(y==5) return 6;
	
	else if(y>5 && t[y]!=-1) return t[y];
	
	else{ int g=tapmak(y-1),o=tapmak(y-2),o1=tapmak(y-3),o2=tapmak(y-4); t[y]=2*g-o+o1-o2; return 2*g-o+o1-o2; }
}

int main()
{
	for(int h=0; h<100; h++)
	t[h]=-1;
	
	scanf("%lld",&n);
	
	printf("%lld",tapmak(n));
	
	getchar();
	
}
