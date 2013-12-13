# include <stdio.h>
# include <stdlib.h>
# include <algorithm>
# include <string.h>

using namespace std;

int gcd(int n,int m)
{
	if(m==0)
	return n;
	
	return gcd(m,n%m);
}

int lcm(int a,int b)
{
return a/gcd(a,b)*b;
}

struct students
{
int a,b;
};

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int m,n=0,a;
students t[200009];
int asd[100009];
int k[200009],p=0;
students l1[100009];
int d[200009];
int ans[100009],b=0;

void tapmak()
{
	int l=0,r=p;
	
	while(r>l)
	{
		if(asd[k[l]-1]!=d[k[l]])
			{l++; continue;}
		
		ans[b++]=k[l];
		d[k[l]]++;
		
		for(int h=l1[k[l]].a; h<=l1[k[l]].b; h++)
		{
			d[t[h].b]++;
			
			if(d[t[h].b]==asd[t[h].b-1])
				k[r++]=t[h].b;
		}
		
		l++;
	}
}

int main()
{
	scanf("%d %d",&m,&a);
	
	for(int h=0; h<a; h++)
	{
		scanf("%d %d",&t[n].a,&t[n].b);
		t[n+1].a=t[n].b;
		t[n+1].b=t[n].a;
		n+=2;
	}
	
	for(int h=0; h<m; h++)
	{
		l1[h+1].b=-17324;
		
		scanf("%d",&asd[h]);
		
		if(asd[h]==0)
			k[p++]=h+1;
	}
	
	qsort(t,n,sizeof(students),function);
	
	l1[1].a=0;
	
	for(int h=1; h<n; h++)
	if(t[h].a!=t[h-1].a)
	{
		l1[t[h-1].a].b=h-1;
		l1[t[h].a].a=h;
	}
	
	
	l1[t[n-1].a].b=n-1;
	
	tapmak();
	
	
	printf("%d \n",b);
	
	for(int h=0; h<b; h++)
	printf("%d ",ans[h]);
}

//qsort(t,n,sizeof(students),function);
