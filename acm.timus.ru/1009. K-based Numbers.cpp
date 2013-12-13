# include <stdio.h>

int n,k;
int z,nz;

int main()
{
	scanf("%d %d",&n,&k);
	
	z=0;
	nz=k-1;
	
	if(k>10)
	{
		z=1;
		nz--;
	}
	
	for(int h=1; h<n; h++)
	{
		int o=z,l=nz;
		
		z=nz;
		nz=(o+l)*(k-1);
		
		if(k>10)
		{
			nz-=(o+l);
			z+=(o+l);
		}
	}
	
	printf("%d",z+nz);
	
}
