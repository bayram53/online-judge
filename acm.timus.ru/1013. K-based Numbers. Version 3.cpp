# include <stdio.h>

int n,k;
int t[3][2009];
bool vis=0;

int main()
{
	scanf("%d %d",&n,&k);
	
	t[0][2000]=k-1;
	
	for(int h=1; h<n; h++)
	{
		for(int j=2000; j>0; j--)
		{
			t[h%2][j]+=t[(h+1)%2][j];
			t[h%2][j-1]+=t[h%2][j]/10;
			t[h%2][j]%=10;
		}
		
		for(int j=2000; j>0; j--)
			t[h%2][j]*=(k-1);
			
		for(int j=2000; j>0; j--)
		{
			t[h%2][j-1]+=t[h%2][j]/10;
			t[h%2][j]%=10;
		}
	}
	
	
	
	for(int j=2000; j>0; j--)
		{
			t[1][j]+=t[0][j];
			t[1][j-1]+=t[1][j]/10;
			t[1][j]%=10;
		}
	
	for(int h=0; h<2001; h++)
	{
		if(t[1][h]!=0)
			vis=1;
		
		if(vis==1)
			printf("%d",t[1][h]);
	}
	
}
