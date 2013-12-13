# include <stdio.h>
# include <string.h>

char c[1009];
int n;
int ans=1,x=0,y=0,a;
int l,r;

int main()
{
	scanf("%s",c);
	n=strlen(c);
	
	for(int h=0; h<n-1; h++)
	{
		a=1;
		
		l=h-1;
		r=h+1;
		
		while(l>=0 && r<n)
		{
			if(c[l]!=c[r])
				break;
			
			l--;
			r++;
			
			a+=2;
		}
		
		if(a>ans)
		{
			ans=a;
			x=l+1;
			y=r-1;
		}
		
		a=0;
		l=h;
		r=h+1;
		
		while(l>-1 && r<n)
		{
			if(c[l]!=c[r])
				break;
			
			l--;
			r++;
			a+=2;
		}
		
		if(a>ans)
		{
			ans=a;
			x=l+1;
			y=r-1;
		}
	}
	
	for(int h=x; h<=y; h++)
	printf("%c",c[h]);
}
