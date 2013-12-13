# include <stdio.h>
# include <algorithm>
# include <string.h>
# define inf 1009

using namespace std;

int n;
char c[109];

struct mal
{
	int a;
	char c[209];
};

mal t[109][109];

mal tapmak(int x,int y)
{
	if(t[x][y].a!=inf)
		return t[x][y];
	
	if(y==x)
	{
		t[x][x].a=2;
		
		if(c[x]=='(' || c[x]==')')
			t[x][x].c[0]='(',t[x][x].c[1]=')';
			
		else
			t[x][x].c[0]='[',t[x][x].c[1]=']';
			
		return t[x][x];
	}
	
	else if(x+1==y)
	{
		t[x][y].a=4;
		
		if((c[x]=='(' && c[y]==')') || (c[x]=='[' && c[y]==']'))
			{t[x][y].c[0]=c[x];t[x][y].c[1]=c[y];t[x][y].a=2;}
			
		else
		{
			if(c[x]==')' || c[x]=='(')
				t[x][y].c[0]='(',t[x][y].c[1]=')';
			
			if(c[y]==')' || c[y]=='(')
				t[x][y].c[2]='(',t[x][y].c[3]=')';
				
			if(c[x]==']' || c[x]=='[')
				t[x][y].c[0]='[',t[x][y].c[1]=']';
			
			if(c[y]==']' || c[y]=='[')
				t[x][y].c[2]='[',t[x][y].c[3]=']';
		}
		
			return t[x][y];
	}
	
	int r=-1,w=0;
	
	for(int h=x; h<y; h++)
	{
		if(t[x][h].a==inf)
			t[x][h]=tapmak(x,h);
			
		if(t[h+1][y].a==inf)
			t[h+1][y]=tapmak(h+1,y);
		
		if(t[x][y].a>t[h+1][y].a+t[x][h].a)
			r=h,t[x][y].a=t[h+1][y].a+t[x][h].a;
	}
	
	for(int h=0; h<t[x][r].a; h++)
		t[x][y].c[w++]=t[x][r].c[h];
	
	for(int h=0; h<t[r+1][y].a; h++)
		t[x][y].c[w++]=t[r+1][y].c[h];
	
	if(((c[x]=='(' && c[y]==')') || (c[x]=='[' && c[y]==']')) && tapmak(x+1,y-1).a+2<t[x][y].a)
	{
		mal f;
		f.a=t[x+1][y-1].a+2;
		f.c[0]=c[x];
		for(int h=0; h<t[x+1][y-1].a; h++)	
			f.c[1+h]=t[x+1][y-1].c[h];
			
		f.c[f.a-1]=c[y];
		swap(f,t[x][y]);
	}
	
	return t[x][y];
}

int main()
{
	scanf("%s",c);
	
	n=strlen(c);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			t[h][j].a=inf;
	
	mal g=tapmak(0,n-1);
	
	for(int h=0; h<g.a; h++)
		printf("%c",g.c[h]);
}
