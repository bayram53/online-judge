# include <stdio.h>
# include <stdlib.h>
# include <algorithm>
# include <string.h>

using namespace std;

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int lcm(int a,int b)
{
return a/gcd(a,b)*b;
}

struct students
{
int a,b;
};

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int n,m,a,b,ans=0;
int t[100009][2];

int main()
{
	scanf("%d %d %d %d",&n,&m,&a,&b);
	
	for(int h=a; h<=n; h++)
	for(int j=b; j<=m; j++)
	if(h>j)
	{
		t[ans][0]=h;
		t[ans][1]=j;
		ans++;
	}
	
	if(ans==0)
	printf("0");
	
	else
	{
		printf("%d\n",ans);
		
		for(int h=0; h<ans; h++)
		printf("%d %d\n",t[h][0],t[h][1]);
	}
}

//qsort(t,n,sizeof(students),function);
