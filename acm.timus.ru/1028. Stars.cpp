# include <stdio.h>
# include <stdlib.h>
# define max1 32768

struct students
{
int a,b,c;
};

int sum[max1];
int ans[max1/2];
int shat,a,n;
students p[max1/2];
char c;

int function (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int function1 (void const *x,void const *y)
{
	students m=*(students*)x;
	students n=*(students*)y;
	
	if(m.b==n.b)
	return m.a-n.a;
	else
	return m.b-n.b;
}


void add(int x,int left,int right,int pos)
{
	sum[pos]++;
	
	if(left==right)
		pos=pos;
	
	else if(x<=(left+right)/2)
		add(x,left,(left+right)/2,pos*2);	
	
	else if(x>(left+right)/2)
		add(x,(right+left)/2+1,right,pos*2+1);	
}

void query(int x,int left,int right,int pos)
{
	if(left==right)
		shat+=sum[pos];
	
	else if(x<=(left+right)/2)
		query(x,left,(left+right)/2,pos*2);
		
	else
	{
		shat+=sum[pos*2];
		query(x,(right+left)/2+1,right,pos*2+1);
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d %d",&p[h].a,&p[h].b);
	
	qsort(p,n,sizeof(students),function1);
	
	
	for(int h=0; h<n; h++)
		p[h].c=h+1;
	
	qsort(p,n,sizeof(students),function);
	
	add(p[0].c,1,max1/2,1);
	ans[0]++;
	
	for(int h=1; h<n; h++)
	{
		shat=0;
		query(p[h].c,1,max1/2,1);
		ans[shat]++;
		add(p[h].c,1,max1/2,1);
	}
	
	for(int h=0; h<n; h++)
		printf("%d\n",ans[h]);
	
	//getchar();
	//getchar();
}
