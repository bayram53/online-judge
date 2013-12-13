# include <stdio.h>

# define mi(x,y) (x<y ? x : y)

int a, mn = 1;
int D[19], F[19];

int main()
{
	scanf("%d",&a);
	
	for(int h=1; h<10; h++)
	{
		scanf("%d",&D[h]);
		if(D[mn] >= D[h])	mn = h;
	}
	
	if(D[mn] > a)	{printf("-1"); return 0;}
	
	F[mn] = a/D[mn];
	int k = F[mn];
	a = a%D[mn];
	
	for(int j=9; j>mn; j--)
		while(a >= D[j]-D[mn]  &&  k)
		{
			k--;
			a -= D[j]-D[mn];
			F[mn]--;
			F[j]++;
		}
	
	for(int h=9; h>0; h--)
		for(int j=0; j<F[h]; j++)	printf("%d",h);
}
