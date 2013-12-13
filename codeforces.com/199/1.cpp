# include <stdio.h>

int n,b,k,r;

int D[100009][5],t[10];

int p[] = {8,4,2,1};

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&b) , t[b]++;
	
	if(t[5]  ||  t[7])	{printf("-1");return 0;}
	
	for(int h=0; h<t[3]; h++)
	{
		if(!t[1]  ||  !t[6])	{printf("-1");return 0;}
		
		D[k][0] = 1;
		D[k][1] = 3;
		D[k][2] = 6;
		k++;
		t[1]--;
		t[6]--;
	}
	
	for(int h=0; h<t[6]; h++)
	{
		if(!t[1]  ||  !t[2])	{printf("-1");return 0;}
		D[k][0] = 1;
		D[k][1] = 2;
		D[k][2] = 6;
		k++;
		t[1]--;
		t[2]--;
	}
	
	for(int j=2; j>-1; j--)
		for(int h=k; h<n/3; h++)
		{
			while(!t[p[r]]){r++;}
			D[h][j] = p[r];
			t[p[r]]--;
		}
	
	for(int h=0; h<n/3; h++)
		if(D[h][0] >= D[h][1]  ||  D[h][1] >= D[h][2]  ||  D[h][1]%D[h][0]  ||  D[h][2]%D[h][1])
			{printf("-1");return 0;}
	
	for(int h=0; h<n/3; h++)	printf("%d %d %d\n",D[h][0],D[h][1],D[h][2]);
}
