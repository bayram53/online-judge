# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct mal1
{
	char c[29];
	int a,b;
};

struct mal
{
	char a[29];
};

int n , x , y , z , m , k = 9999999 , f;
mal c[109];
mal1 d[109];

int so(void const *x,void const *y)
{
	mal1 m = *(mal1*)x;
	mal1 n = *(mal1*)y;
	
	return m.b - n.b;
}

int so1(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return strcmp(m.a , n.a);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s %d:%d.%d",d[h].c,&x,&y,&z);
		
		y += z/10;
		z %= 10;
		x += y/60;
		y %= 60;
			
		int k = x * 1000 + y * 10 +z;
		
		d[h].a = k;
		
		y += f;
		x += y/60;
		y %= 60;
		
		d[h].b = x * 1000 + y * 10 + z;
		
		f += 30;
	}
	
	qsort(d , n , sizeof(mal1) , so);
	
	for(int h=0; h<n; h++)
		if(k > d[h].a)
		{
			k = d[h].a;
			
			int f = strlen(d[h].c);
			
			for(int j=0; j<f; j++)
				c[m].a[j] = d[h].c[j];
			m++;
		}
	
	qsort(c , m , sizeof(mal) , so1);
	
	printf("%d",m);
	
	for(int h=0; h<m; h++)
		printf("\n%s",c[h].a);
}
