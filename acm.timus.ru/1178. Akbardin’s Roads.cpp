# include <stdio.h>
# include <stdlib.h>

struct mal
{
	int a,b,c;
};

mal t[10009];
int n,k=0;

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.a==n.a)
		return m.b-n.b;
	return m.a-n.a;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&t[h].a,&t[h].b),t[h].c=h+1;
	
	qsort(t,n,sizeof(mal),so);
	
	for(int h=0; h<n/2; h++)
		printf("%d %d\n",t[k].c,t[k+1].c),k+=2;
}
