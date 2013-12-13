# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <string.h>

using namespace std;

int n;
int t[100009];
int x=0,y=0;
int a=0,b=0,c=0;

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	for(int h=1; h<n; h++)
		if(t[h]<t[h-1])
			a=1;
	
	for(int h=1; h<n; h++)
		if(t[h]>t[h-1])
			b=1;
			
	if(t[0]==t[n-1])
		c=1;
	
	if(((a==0 || b==0) && c==1) || n==1 || n==2)
	{
		printf("-1");
		return 0;
	}
	
	if(a==0 || b==0)
	{
		a=0;
		b=0;
		swap(t[n-2],t[0]);
		
		for(int h=1; h<n; h++)
			if(t[h]<t[h-1])
				a=1;
		
		for(int h=1; h<n; h++)
			if(t[h]>t[h-1])
				b=1;
				
		if(a!=0 && b!=0)
		{
			printf("1 %d",n-1);
			return 0;
		}
		a=0;
		b=0;
		swap(t[0],t[n-2]);
		swap(t[0],t[n-1]);
		
		for(int h=1; h<n; h++)
			if(t[h]<t[h-1])
				a=1;
		
		for(int h=1; h<n; h++)
			if(t[h]>t[h-1])
				b=1;
				
		if(a!=0 && b!=0)
		{
			printf("1 %d",n);
			return 0;
		}
		a=0;
		b=0;
		swap(t[0],t[n-1]);
		swap(t[1],t[n-1]);
		
		
		for(int h=1; h<n; h++)
			if(t[h]<t[h-1])
				a=1;
		
		for(int h=1; h<n; h++)
			if(t[h]>t[h-1])
				b=1;
				
		if(a!=0 && b!=0)
		{
			printf("2 %d",n);
			return 0;
		}
		a=0;
		b=0;
		swap(t[1],t[n-1]);
		swap(t[1],t[n-2]);
		
		for(int h=1; h<n; h++)
			if(t[h]<t[h-1])
				a=1;
		
		for(int h=1; h<n; h++)
			if(t[h]>t[h-1])
				b=1;
				
		if(a!=0 && b!=0)
		{
			printf("2 %d",n-1);
			return 0;
		}
	}
	
	int p=-1,f;
	for(int h=0; h<n; h++)
		if(p<t[h])
			p=t[h],f=h;
			
			
	int p1=-1,f1;	
	for(int h=0; h<n; h++)
		if(p1<t[h] && h!=f)
			p1=t[h],f1=h;
			
	int p2=9999999,f2;
	
	for(int h=0; h<n; h++)
		if(p2>t[h])
			p2=t[h],f2=h;
			
	if((f2<f && f1<f2) || (f2>f && f1>f2))
		printf("%d %d",f+1,f1+1);
		
	if((f2<f1 && f1<f) || (f2>f1 && f1>f))
		printf("%d %d",f1+1,f2+1);
		
	if((f2<f && f<f1) || (f2>f && f>f1))
		printf("%d %d",f1+1,f2+1);
}
