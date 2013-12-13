# include <stdio.h>

int N,x,y;

char S[1009];

int main()
{
	scanf("%d %s",&N,S);
	
	for(int h=0; h<N; h++)
		if(S[h] != '.')	{x = h; break;}
	
	for(int h=N-1; h>-1; h--)
		if(S[h] != '.'){y=h;break;}
	
	if(S[x] == S[y]){printf("%d %d",x+1,y+2);return 0;}
	
	if(S[x] == 'R')
	{
		printf("%d ",x+1);
		
		for(int h=0; h<N; h++)
			if(S[h] != '.'  &&  S[h] != S[x]){printf("%d",h);return 0;}
	}
	
	else
	{
		printf("%d %d ",x+1,y+1);
		
	}
}
