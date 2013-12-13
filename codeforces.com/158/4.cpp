# include <stdio.h>
# include <algorithm>
# include <vector>
# include <stdlib.h>

# define MAXN 100009
# define mi(x,y) (x<y ? x : y)

using namespace std;

struct mal
{
	int id,c;
};

int n,x,y,a,b;

mal A[MAXN];
mal B[MAXN];

int ans[MAXN][4];

int so(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return n.c-m.c;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&x,&y);
		if(x)	B[b].c = y , B[b++].id = h+1;
		else 	A[a].c = y , A[a++].id = h+1;
	}
	
	qsort(A , a , sizeof(mal) , so);
	qsort(B , b , sizeof(mal) , so);
	a--;	b--;
	
	x = 0;
	
	while(1)
	{
		if(A[a].c == B[b].c)
		{
			ans[x][0] = A[a].id;
			ans[x][1] = B[b].id;
			ans[x++][2] = A[a].c;
			
			if(!a  &&  !b)	break;
			
			if(!a)	{b--; continue;}
			if(!b)	{a--;continue;}
			ans[x][0] = B[b].id , ans[x][1] = A[a-1].id;
			a--; b--;
			ans[x++][2] = 0;
		}
		
		else
		{
			int k = mi(A[a].c,B[b].c);
			
			ans[x][0] = A[a].id;
			ans[x][1] = B[b].id;
			ans[x++][2] = k;
			
			if(A[a].c < B[b].c)	a-- , B[b].c -= k;
			else 	b-- , A[a].c -= k;
		}
	}
	
	for(int h=0; h<x; h++)	printf("%d %d %d\n",ans[h][0],ans[h][1],ans[h][2]);
}
