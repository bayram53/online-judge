# include <stdio.h>

int t[10];

int main()
{
	for(int h=0; h<7; h++)
		scanf("%d",&t[h]);
	
	for(int h=0; h<8; h++)
	{
		t[h]=(t[h]+1)%2;
		
		if((t[0]+t[1]+t[3])%2==t[6] && (t[0]+t[2]+t[3])%2==t[5] && (t[2]+t[1]+t[3])%2==t[4])
		{
			for(int h=0; h<7; h++)
				printf("%d ",t[h]);
				
			return 0;
		}
		
		t[h]=(t[h]+1)%2;
	}
}
