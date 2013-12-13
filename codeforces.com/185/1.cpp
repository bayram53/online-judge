# include <stdio.h>
# include <string.h>
# include <iostream>

using namespace std;

int n;
char c[109],a;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<=n; h++)
	{
		int d = 0;
		
		while(1)
		{
			scanf("%c",&a);//printf("__%c__\n",a);
			if(a == '\n')	break;
			c[d++] = a;
		}
		
		if(!h)	continue;
		
		if(d < 5)	{printf("OMG>.< I don't know!\n");continue;}
		
		if(c[0] == 'm'  &&  c[1] == 'i'  &&  c[2] == 'a'  &&  c[3] == 'o'  &&  c[4] == '.'  &&  c[d-1] == '.'  &&  c[d-2] == 'a'  &&  c[d-3] == 'l'  &&  c[d-4] == 'a'  &&  c[d-5] == 'l')	printf("OMG>.< I don't know!\n");
		
		else if(c[0] == 'm'  &&  c[1] == 'i'  &&  c[2] == 'a'  &&  c[3] == 'o'  &&  c[4] == '.')	printf("Rainbow's\n");
		
		else if(c[d-1] == '.'  &&  c[d-2] == 'a'  &&  c[d-3] == 'l'  &&  c[d-4] == 'a'  &&  c[d-5] == 'l') 	printf("Freda's\n");
		
		else printf("OMG>.< I don't know!\n");
	}
}
                                                                                                   
