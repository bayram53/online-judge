# include <iostream>
# include <algorithm>
# include <stdio.h>
# include <stdlib.h>
# include <vector>

using namespace std;

struct students
{
int a,b;
};

vector< vector<int> > person(70009);
students t[70009];
int n,san=1;
int shat[70009],q,x,y,l;
int ans[70009],k,c;

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int binary1(vector<int> d,int x,int y,int x1,int y1)
{
	if(abs(x-y)<2)
	{
		if(d[x]<=y1 && d[x]>=x1)
			return 1;
			
		if(d[y]<=y1 && d[y]>=x1)
			return 1;
			
		return -1;
	}
	
	if(d[(x+y)/2]<=y1 && d[(x+y)/2]>=x1)
		return 1;
	
	if(d[(x+y)/2]>x1 && d[(x+y)/2]>y1)
		return binary1(d,x,(x+y)/2,x1,y1);
		
	return  binary1(d,(x+y)/2+1,y,x1,y1);
	
}

int binary(int *d,int x,int y,int a)
{
	if(abs(x-y)<2)
	{
		if(d[x]==a)
			return x;
			
		else if(d[y]==a)
			return y;
			
		return -1;
	}
	
	if(d[(x+y)/2]==a)
		return (x+y)/2;
	
	if(d[(x+y)/2]>a)
		return binary(d,x,(x+y)/2,a);
		
	return  binary(d,(x+y)/2+1,y,a);
	
}

int main()
{
	for(int h=0; h<70009; h++)
		person[h].resize(1);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d",&t[h].a);
		t[h].b=h+1;
	}
	
	qsort(t,n,sizeof(students),function);
	
	person[0].push_back(t[0].b);
	shat[1]=t[0].a;
	
	for(int h=1; h<n; h++)
	{
		if(shat[san]!=t[h].a)
		{
			person[san].push_back(t[h].b);
			shat[++san]=t[h].a;
		}
		
		else
			person[san-1].push_back(t[h].b);
		
		
	}
	
	scanf("%d",&q);
	
	for(int h=0; h<q; h++)
		ans[h]=1;
	
	for(int h=0; h<q; h++)
	{
		scanf("%d %d %d",&x,&y,&l);
		c=binary(shat,1,san,l);
		
		if(c==-1)
		{
			ans[h]=0;
			continue;
		}
		
		k=binary1(person[c-1],1,person[c-1].size(),x,y);
		
		if(k==-1)
		{
			ans[h]=0;
			
		}
	}
	
	for(int h=0; h<q; h++)
		printf("%d",ans[h]);
	
}
