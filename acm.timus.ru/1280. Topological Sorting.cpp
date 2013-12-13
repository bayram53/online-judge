# include <stdio.h>

int n,m,a,ans=0;
int t[100000][2];
int pl[1009];

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
		scanf("%d %d",&t[h][0],&t[h][1]);
	
	for(int h=0; h<n; h++)
		scanf("%d",&a),pl[a]=h;
	
	for(int h=0; h<m; h++)
		if(pl[t[h][0]]>=pl[t[h][1]])
			ans=1;
	
	if(ans==0)
		printf("YES");
	
	else
		printf("NO");
}
