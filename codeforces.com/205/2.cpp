# include <stdio.h>
# include <algorithm>

using namespace std;

int n, a, b, k, l, t;

int D[2009], san[2009], ans[2009], bir[2009], iki[2009];

struct mal
{
	int a, fr;
} T[109];

int so(void const *x, void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return n.fr-m.fr;
}

int main()
{
	a = b = k = l = 0;
	scanf("%d",&n);
	
	for(int h=0; h<2*n; h++)
	{
		scanf("%d",&D[h]);
		san[D[h]]++;
	}
	
	for(int j=10; j<100; j++)	T[t].a = j, T[t++].fr = san[j];
	
	qsort(T, t, sizeof(mal), so);
	
	for(int j=0; j<t; j++)
		for(int i=0; i<T[j].fr; i++)
			for(int h=0; h<2*n; h++)
				if(D[h] == T[j].a)
				{
					if(a < b)	a++, ans[h] = 1, bir[T[j].a] = 1;
					else	b++, ans[h] = 2, iki[T[j].a] = 1;
				}
	
	for(int h=0; h<n; h++)
		for(int h=0; h<n; h++)
			for(int h=0; h<n; h++)
	
	for(int h=10; h<100; h++)
	{
		k += bir[h];
		l += iki[h];
	}
	
	printf("%d\n",k*l);
	printf("%d",ans[0]);
	for(int h=1; h<2*n; h++)	printf(" %d",ans[h]);
}
/*
5
10 20 30 30 30 40 50 50 50 60
*/
