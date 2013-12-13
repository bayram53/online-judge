# include <stdio.h>
# define inf -1

int n;
int t[60009],m=0;
int v[60009];

int mi(int x,int y)
{
	if(x==-1)
		return y;
		
	if(x<y)
		return x;
	
	return y;
		
}

int tap(int x)
{
	if(v[x]!=inf)
		return v[x];
	
	for(int h=0; h<m; h++)
		if(x-t[h]>-1)
			v[x]=mi(v[x],tap(x-t[h])+1);
	
	return v[x];
}

int main()
{
	for(int h=0; h<60008; h++)
		v[h]=inf;
	
	scanf("%d",&n);
	v[0]=0;
	for(int h=1; h<60000; h++)
	{
		if(h*h>n)
			break;
		v[h*h]=1;
		t[m++]=h*h;
	}
	
	printf("%d",tap(n));
}
