# include <stdio.h>

int n,k;

int kn[100009][109];

int d[109];

bool v[109];

int main()
{
	scanf("%d %d",&k,&n);
	
	kn[0][100] = 1;
	
	for(int h=0; h<n; h++)	scanf("%d",&d[h]);
	
	for(int h=n-1; h>-1; h--)
		for(int j=k-d[h]; j>-1; j--)
			if(kn[j][100])	kn[j+d[h]][100]++ , kn[j+d[h]][h] = 1;
	
	if(!kn[k][100])	printf("0");
	else if(kn[k][100] > 1)	printf("-1");
	else
	{
		while(k)
		{
			int p;
			
			for(int h=n-1; h>-1; h--)	if(kn[k][h])	{p=h; break;}
			
			v[p+1] = 1;
			
			k -= d[p];
		}
		
		for(int h=1; h<=n; h++)	if(!v[h])	printf("%d ",h);
	}
}
