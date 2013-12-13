# include <stdio.h>
# include <string.h>

# define ma(x,y) (x>y ? x : y)

int n,m,ans;

char s[209];

char f[19][209];

int g[19][4];

int a[40009][2],b;

int main()
{
	scanf("%s",s);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s %d %d",f[h],&g[h][0],&g[h][1]);
		g[h][2] = strlen(f[h]);
	}
	
	 m = strlen(s);
	
	for(int h=0; h<m; h++)
		for(int j=h; j<m; j++)
		{
			int v = 0;
			
			for(int i=0; i<n; i++)
			{
				int k = 0 , t = j-h+1;
				
				for(int l=0; l<=g[i][2]-t; l++)
				{
					bool p = 0;
					
					for(int r=l; r<l+t; r++)
						if(s[h+r-l] != f[i][r])
							{p = 1;break;}
					
					if(!p) k++;
				}
				
				if(k >= g[i][0]  &&  k <= g[i][1])	v++;
				else break;
			}
			
			if(v == n)	a[b][0] = h , a[b++][1] = j;
		}
	
	for(int h=0; h<b; h++)
	{
		int p=1;
		//for(int j=a[h][0]; j<=a[h][1]; j++)	printf("%c",s[j]);printf("\n");
		for(int j=0; j<h; j++)
		{
			if(a[h][1]-a[h][0] != a[j][1]-a[j][0]) continue;
			
			bool w=0;
			
			for(int i=0; i<a[h][1]-a[h][0]+1; i++)
				if(s[a[h][0]+i] != s[a[j][0]+i])
				{
					w = 1;
					break;
				}
			
			if(!w)	{p=0; break;}
		}
		
		if(p)	ans++;
	}
	
	printf("%d\n",ans);
}
