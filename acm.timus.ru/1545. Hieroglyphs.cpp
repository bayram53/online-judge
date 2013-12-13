# include <stdio.h>

int n,m;
char a[10009][10],b;

int main()
{
	scanf("%d\n",&n);
	
	for(int h=0; h<n; h++)
		scanf("%s",a[h]);
		
	scanf("\n%c",&b);
		
	for(int h=0; h<n; h++)
		if(a[h][0]==b)
			printf("%s\n",a[h]);
}
