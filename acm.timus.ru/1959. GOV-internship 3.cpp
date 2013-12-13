# include <stdio.h>
# include <algorithm>

# define mi(x,y) (x<y ? x : y)
# define ma(x,y) (x>y ? x : y)
# define MAXT 100000

using namespace std;

struct mal
{
	int id,cost;
};

int n1,m1,a,b;

int n[100009];

int m[100009];

mal he[100009];

int pos[100009];

void print()
{
	for(int h=0; h<n1; h++)	printf("%d ",n[h]);	printf("\n");
	for(int j=0; j<m1; j++)	printf("%d ",m[j]);
}

void upd_up(int x)
{
	int a = pos[x];
	
	he[a].cost++;
	
	while(a != 1  &&  he[a/2].cost < he[a].cost)
	{
		swap(pos[he[a/2].id] , pos[he[a].id]);
		swap(he[a] , he[a/2]);
		a /= 2;
	}
}

void upd_down(int x)
{
	int a = pos[x];
	
	he[a].cost--;
	
	while((a*2 <= MAXT  &&  he[a*2].cost > he[a].cost)  ||  (a*2+1 <= MAXT  &&  he[a*2+1].cost > he[a].cost))
	{
		if(a*2+1 <= MAXT  &&  he[a*2+1].cost >= he[a*2].cost)
		{
			swap(pos[he[a*2+1].id] , pos[he[a].id]);
			swap(he[a*2+1] , he[a]);
			a = a*2+1;
		}
		
		else
		{
			swap(pos[he[a*2].id] , pos[he[a].id]);
			swap(he[a*2] , he[a]);
			a *= 2;
		}
	}
}

int main()
{
	for(int h=1; h<=MAXT; h++)	pos[h] = h , he[h].id = h;
	
	scanf("%d",&n1);
	
	for(int h=0; h<n1; h++)
	{
		scanf("%d",&n[h]);
		if(!n[h])	a = 1;
	}
	
	scanf("%d",&m1);
	
	for(int h=0; h<m1; h++)
	{
		scanf("%d",&m[h]);
		if(!m[h])	b = 1;
	}
	
	if(a + b == 0)	print();
	
	else if(a)
	{
		int t = 0;
		
		for(int h=0; h<n1; h++)
		{
			if(h < m1)	upd_up(m[h]);
			
			if(!n[h])	n[h] = he[1].id;
			
			if(n1-h <= m1)	upd_down(m[t++]);
		}
		
		print();
	}
	
	else
	{
		int t = n1-m1+1;
		
		for(int h=0; h<t; h++)	upd_up(n[h]);
		
		for(int h=0; h<m1; h++)
		{
			if(!m[h])	m[h] = he[1].id;
			
			upd_down(n[h]);
			upd_up(n[t++]);
		}
		
		print();
	}
}
