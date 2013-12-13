# include <stdio.h>
# include <algorithm>
# include <vector>
# include <string.h>

using namespace std;

int n,a,b,d,f=1;

vector < vector <int> > ch(1009);
vector < vector <int> > pa(1009);

char c[10],e[10];

int ans;

int t[1009];

int tap(char *r)
{
	int p = 0;
	int k = strlen(r);
	
	for(int h=0; h<k; h++)	p *= 10 , p += r[h]-48;
	
	return p;
}

void child(int x)
{
	t[x] = 1;
	
	for(int h=0; h<(int)ch[x].size(); h++)	child(ch[x][h]);
}

void par(int x)
{
	t[x] = 1;
	
	for(int j=0; j<(int)pa[x].size(); j++)	par(pa[x][j]);
}

int main()
{
	scanf("%d",&n);
	
	while(scanf("%s",c)!=EOF)
	{
		if(c[0] == 'B')
		{
			d = 1; 
			
			while(1)
			{
				int w = strlen(c); 
				
				if(c[w-1] == 'D')	break;
				
				scanf("%s",c);
			}
			
			continue;
		}
		
		if(!d)	scanf("%s",e);
		
		a = tap(c);
		b = tap(e);
		
		if(d)	par(a),child(a);
		else 	ch[b].push_back(a) , pa[a].push_back(b);
		
		//if(a == 8  &&  d)	break;
	}
	
	for(int h=1; h<=n; h++)	if(!t[h])	f = 0 , printf("%d ",h);
	
	if(f)	printf("0");
}
