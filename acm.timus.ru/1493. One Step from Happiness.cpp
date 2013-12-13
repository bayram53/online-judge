# include <stdio.h>

char c;
int a[10];
int b[10];

int main()
{
	for(int h=0; h<6; h++)
	{
		scanf("%c",&c);
		a[h]=c-48;
		b[h]=a[h];
	}
	
	a[5]--;
	b[5]++;
	
	for(int h=5; h>0; h--)
	if(a[h]==-1)
	{
		a[h]=9;
		a[h-1]--;
	}
	
	for(int h=5; h>0; h--)
	if(b[h]==10)
	{
		b[h]=0;
		b[h-1]++;
	}
	
	if(a[0]+a[1]+a[2]==a[3]+a[4]+a[5] || b[0]+b[1]+b[2]==b[3]+b[4]+b[5])
		printf("Yes");
		
	else
		printf("No");
}
