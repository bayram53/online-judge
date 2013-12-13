# include <stdio.h>

int n,l,m,e;
char k[109];

void input()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s Penguin",k);
		if(k[0]=='L')
			l++;
		else if(k[0]=='E')
			e++;
		else
			m++;
	}
}

void output()
{
	if(e>=l && e>=m)
		printf("Emperor Penguin");
		
	else if(l>=e && l>=m)
		printf("Little Penguin");
		
	else
		 printf("Macaroni Penguin");
		
}

int main()
{
	input();
	output();
	
}
