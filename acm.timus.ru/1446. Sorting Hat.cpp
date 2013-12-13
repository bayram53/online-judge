# include <stdio.h>
# include <string.h>

char c[5][1009][209],a;
int n,k,b,p;
int d[5];
char x[209],y[209];

int main()
{
	scanf("%d\n",&n);
	
	while(k != 2*n)
	{
		scanf("%c",&a);
		
		if(a == '\n')
		{
			p=0;
			
			k++;
			
			if(k % 2 == 0)
			{
				b  = strlen(x);
				
				if(strcmp(y ,"Slytherin") == 0){
					for(int h=0; h<b; h++)
						c[0][d[0]][h] = x[h];	d[0]++;}
				
				if(strcmp(y ,"Hufflepuff") == 0){
					for(int h=0; h<b; h++)
						c[1][d[1]][h] = x[h];	d[1]++;}
						
				if(strcmp(y ,"Gryffindor") == 0){
					for(int h=0; h<b; h++)
						c[2][d[2]][h] = x[h];	d[2]++;}
				
				if(strcmp(y ,"Ravenclaw") == 0){
					for(int h=0; h<b; h++)
						c[3][d[3]][h] = x[h];	d[3]++;}
				memset(y,0,sizeof(y));
				memset(x,0,sizeof(x));
			}
		}
		
		else
		{
			if(k % 2 == 1)
				y[p++]=a;
			else
				x[p++]=a;
		}
	}
	
	printf("Slytherin:\n");
	
	for(int h=0; h<d[0]; h++)
		printf("%s\n",c[0][h]);
	printf("\n");
	
	printf("Hufflepuff:\n");
	
	for(int h=0; h<d[1]; h++)
		printf("%s\n",c[1][h]);
	printf("\n");
	
	printf("Gryffindor:\n");
	
	for(int h=0; h<d[2]; h++)
		printf("%s\n",c[2][h]);
	printf("\n");
	
	printf("Ravenclaw:\n");
	
	for(int h=0; h<d[3]; h++)
		printf("%s\n",c[3][h]);
}
