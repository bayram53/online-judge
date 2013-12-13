# include <stdio.h>
# include <string.h>

char c[10][10],s[10][10];

bool barla()
{
	for(int h=0; h<3; h++)
		for(int j=0; j<3; j++)
			if((s[h][j] == '#'  &&  s[h+1][j] == '#'  &&  s[h][j+1] == '#'  &&  s[h+1][j+1] == '#') ||
			(s[h][j] == '.'  &&  s[h+1][j] == '.'  &&  s[h][j+1] == '.'  &&  s[h+1][j+1] == '.'))
				return 1;
	return 0;
}

int main()
{
	scanf("%s%s%s%s",c[0],c[1],c[2],c[3]);
	
	for(int h=0; h<4; h++)
		for(int j=0; j<4; j++)
			s[h][j] = c[h][j];
	
	if(barla())
	{
		printf("YES");
		return 0;
	}
	
	for(int h=0; h<4; h++)
		for(int j=0; j<4; j++)
		{
			if(s[h][j] == '#')
				s[h][j] = '.';
			else
				s[h][j] = '#';
			
			if(barla())
			{
				printf("YES");
				return 0;
			}
			
			for(int h=0; h<4; h++)
				for(int j=0; j<4; j++)
					s[h][j] = c[h][j];
		}
		
	printf("NO");
}
