# include <stdio.h>
# include <string.h>

char sandro[209],s1[209];
char word[]={"Sandro"};
int a,ans=53;

int main()
{
	scanf("%s",sandro);
	
	int k=strlen(sandro);
	
	for(int h=0; h<k-5; h++)
	{
		a=0;
		
		if(sandro[h]-65>30)
		{
			a++;
			s1[0]=sandro[h]-32;
		}
		
		else
			s1[0]=sandro[h];
		
		for(int j=h+1; j<h+6; j++)
		{
			if(sandro[j]-65<30)
			{
				a++;
				s1[j-h]=sandro[j]+32;
			}
		
			else
				s1[j-h]=sandro[j];
		}
		
		
		for(int j=0; j<6; j++)
			if(s1[j]!=word[j])
				a++;
		
		if(a<ans)
			ans=a;
	}
	
	printf("%d",ans*5);
	
}
