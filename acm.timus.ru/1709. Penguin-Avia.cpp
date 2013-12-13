# include <stdio.h>

long long n,d2,a;
long long ans=0;
char s[1009][1009];
int t[1009][1009];
bool vis[1009];
bool f[1009][1009];
bool p[1009];
int d[1009],d1=0;

void bfs(int x)
{
	int b[1009],x1=1,y=0;
	b[0]=x;
	d[d1++]=x;
	p[x]=1;
	
	while(x1>y)
	{
		for(int h=1; h<=n; h++)
			if(t[b[y]-1][h-1]==1 && f[b[y]][h]==0)
			{
				if(vis[h]!=1 && p[h]==1)
					ans+=d2,s[b[y]][h]='d',s[h][b[y]]='d';
					
				if(p[h]==0)
					b[x1++]=h,f[h][b[y]]=1,f[b[y]][h]=1,p[h]=1;
			}
		vis[b[y]]=1;
		y++;
	}
	
}

int main()
{
	for(int h=0; h<109; h++)
		for(int j=0; j<109; j++)
			s[h][j]='0';
	
	scanf("%lld %lld %lld",&n,&d2,&a);
	
	for(int h=0; h<n; h++)
		for(int j=0; j<n; j++)
			scanf("%1d",&t[h][j]);
			
	
	for(int h=1; h<=n; h++)
		if(vis[h]==0)
			bfs(h);
	
	for(int h=1; h<d1; h++)
		s[d[h-1]][d[h]]='a',ans+=a,s[d[h]][d[h-1]]='a';
		
	printf("%lld\n",ans);
	
	for(int h=1; h<=n; h++){
		for(int j=1; j<=n; j++)
			printf("%c",s[h][j]);printf("\n");}
}
