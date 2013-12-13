# include <stdio.h>
# include <string.h>

int n;
char c[20][3][25];
int t[21][21];
bool p[20];
bool o[20][20];
int ans;

void tap(int x)
{
	if(x==n)
	{
		int k[20],as=0,m=0;
		for(int h=0; h<20; h++)
			k[h]=0;
		
		for(int h=0; h<n; h++)
			if(p[h]==1){
				for(int j=0; j<t[h][20]; j++)
					k[t[h][j]]++;as++;}
			
		for(int h=0; h<n; h++)
			if(p[h]==0 && t[h][20]-k[h]==0)
				m++;
		
		if(n==m+as && ans<m)
			ans=m;
	}
	
	else
	{
		p[x]=0;tap(x+1);
		p[x]=1;tap(x+1);
	}
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s %s %s",c[h][0],c[h][1],c[h][2]);
		
		for(int i=0; i<3; i++)
			for(int j=0; j<h; j++)
				if((strcmp(c[h][i],c[j][0])==0 || strcmp(c[h][i],c[j][1])==0 || strcmp(c[h][i],c[j][2])==0) && o[h][j]==0)
					t[h][t[h][20]++]=j,t[j][t[j][20]++]=h,o[h][j]=1,o[j][h]=1;
	}
	
	tap(0);
	
	printf("%d",ans);
}
