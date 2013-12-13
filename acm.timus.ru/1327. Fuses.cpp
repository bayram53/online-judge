# include <stdio.h>

int n,m;
int asd=0;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=n; h<=m; h++)
		if(h%2==1)
			asd++;
		
	printf("%d",asd);
}
