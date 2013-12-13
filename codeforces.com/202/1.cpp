# include <stdio.h>

int n, a;
int D[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&a);
		
		if(a == 25)	D[a]++;
		
		else if(a == 50)
		{
			if(D[25])	D[25]--;
			else 	{printf("NO");return 0;}
			D[a]++;
		}
		
		else if(a == 75)
		{
			if(D[50])	D[50]--;
			else if(D[25] > 1)	D[25] -= 2;
			else 	{printf("NO");return 0;}
			D[a]++;
		}
		
		else
		{
			if(D[75])	D[75]--;
			else if(D[50]  &&  D[25])	D[50]--, D[25]--;
			else if(D[25] > 2)	D[25] -= 3;
			else 	{printf("NO");return 0;}
		}
		
	}
	
	printf("YES");
}
