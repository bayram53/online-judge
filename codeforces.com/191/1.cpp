# include <stdio.h>

int n,ans;
int D[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%d",&D[h]);
	
	for(int h=0; h<n; h++)
		for(int j=h; j<n; j++)
		{
			int s = 0;
			
			for(int i=0; i<n; i++)
			{
				if(h <= i  &&  j >= i)		s += 1-D[i];
				else s += D[i];
			}
			
			if(s > ans)	ans = s;
		}
	printf("%d\n",ans);
}
