# include <stdio.h>
# include <string.h>

int n;
char c[10000009];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",c);
		
		int m=strlen(c),i=0;
		bool ans=0;
		
		while(i<m && ans==0)
		{
			if(c[i]=='p' && c[i+1]=='u'  && c[i+2]=='t' && c[i+3]=='o' && c[i+4]=='n')
				i+=5;
			
			else if(c[i] == 'o'  &&  c[i+1] == 'n'  &&  c[i+2] == 'e')
				i+=3;
			
			else if(c[i] == 'o'  &&  c[i+1] == 'u'  &&  c[i+2] == 't')
			{
				i+=3;

				if(c[i] == 'p'  &&  c[i+1] == 'u'  && c[i+2] == 't' &&  (c[i+3] != 'o'  || c[i+4]!='n'  || c[i+5]=='e'))
					i+=3;
			}
			
			else if(c[i] == 'i' && c[i+1]=='n')
			{
				i+=2;
				
				if(c[i] == 'p'  &&  c[i+1] == 'u'  && c[i+2] == 't' &&  (c[i+3] != 'o'  || c[i+4]!='n'  || c[i+5]=='e'))
					i+=3;
			}
			
			else
				ans=1;
		}
		
		if(ans==0 && i==m)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
