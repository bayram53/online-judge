# include <stdio.h>

int n,m,a,c,t,v;

int d[100009][3];

int b_s(int x,int l,int r)
{
	if(r-l < 2)
	{
		if(d[l][0] <= x  &&  d[l][1] >= x)	return l;
		return r;
	}
	
	int to = (l+r)/2;
	
	if(d[to][1] < x)	return b_s(x,to,r);
	return b_s(x,l,to);
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d",&c,&t);
		
		d[h][0] = a+1;
		d[h][1] = a+t*c;
		a += t*c;
	}
	
	for(int h=0; h<m; h++)
	{
		scanf("%d",&v);
		printf("%d\n",b_s(v,0,n-1)+1);
	}
}
