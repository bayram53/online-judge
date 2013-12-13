# include <stdio.h>
# include <algorithm>

using namespace std;

int d[30];
int a , ans = 9999;
int g[10][3];
int d1[96];
int x[] = {2 , 8 , 15 , 9};
int y[] = {3 , 12 , 14 , 5};
int z[] = {6 , 7 , 11 , 10};
int t[] = {1 , 4 , 16 , 13};

void tap(int x1 = 0)
{
	if(x1 == 4)
	{
		int f;
		
		for(int h=1; h<17; h++)
			d[h] = d1[h];
		
		if(d[x[0]] + d[x[1]] + d[x[2]] + d[x[3]] == 10)
		{
			if(g[0][1] == 0)
				for(int h=0; h<g[0][0]; h++)
					f = d[x[0]] , d[x[0]] = d[x[1]] , d[x[1]] = d[x[2]] , d[x[2]] = d[x[3]] , d[x[3]] = f;
			else
				for(int h=0; h<g[0][0]; h++)
					f =d [x[0]] , d[x[0]] = d[x[3]] , d[x[3]] = d[x[2]] , d[x[2]] = d[x[1]] , d[x[1]] = f;
		}
		
		if(d[y[0]] + d[y[1]] + d[y[2]] + d[y[3]] == 10)
		{
			if(g[1][1] == 0)
				for(int h=0; h<g[1][0]; h++)
					f = d[y[0]] , d[y[0]] = d[y[1]] , d[y[1]] = d[y[2]] , d[y[2]] = d[y[3]] , d[y[3]] = f;
			else
				for(int h=0; h<g[1][0]; h++)
					f = d[y[0]] , d[y[0]] = d[y[3]] , d[y[3]] = d[y[2]] , d[y[2]] = d[y[1]] , d[y[1]] = f;
		}
		
		if(d[z[0]] + d[z[1]] + d[z[2]] + d[z[3]] == 10)
		{
			if(g[2][1] == 0)
				for(int h=0; h<g[2][0]; h++)
					f = d[z[0]] , d[z[0]] = d[z[1]] , d[z[1]] = d[z[2]] , d[z[2]] = d[z[3]] , d[z[3]] = f;
			else
				for(int h=0; h<g[2][0]; h++)
					f = d[z[0]] , d[z[0]] = d[z[3]] , d[z[3]] = d[z[2]] , d[z[2]] = d[z[1]] , d[z[1]] = f;
		}
		
		if(d[t[0]] + d[t[1]] + d[t[2]] + d[t[3]] == 10)
		{
			if(g[3][1] == 0)
				for(int h=0; h<g[3][0]; h++)
					f = d[t[0]] , d[t[0]] = d[t[1]] , d[t[1]] = d[t[2]] , d[t[2]] = d[t[3]] , d[t[3]] = f;
			else
				for(int h=0; h<g[3][0]; h++)
					f = d[t[0]] , d[t[0]] = d[t[3]] , d[t[3]] = d[t[2]] , d[t[2]] = d[t[1]] , d[t[1]] = f;
		}
		
		bool p=0;
		f = 0;
		
			if(d[1] != d[1+1]  ||  d[1] != d[1+4]  || d[1] != d[1+5]
			|| d[3] != d[3+1]  ||  d[3] != d[3+4]  || d[3] != d[3+5]
			|| d[9] != d[9+1]  ||  d[9] != d[9+4]  || d[9] != d[9+5]
			|| d[11] != d[11+1]  ||  d[11] != d[11+4]  || d[11] != d[11+5])
				p = 1;
		
		for(int h=0; h<4; h++)
			f+=g[h][0];
		
		if(p == 0  &&  ans > f)
			ans = f;
	}
	
	else
	{
		for(int h=0; h<4; h++)
		{
			g[x1][0] = h;
			
			g[x1][1] = 0; tap(x1+1);
			g[x1][1] = 1; tap(x1+1);
		}
		
	}
}

int main()
{
	for(int h=0; h<4; h++)
		for(int j=1; j<5; j++)
		{
			scanf("%d",&a);
			d[h * 4 + j] = a;
			d1[h * 4 + j] = a;
		}
	
	tap();
	
	printf("%d",ans);
}
