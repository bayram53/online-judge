# include <stdio.h>
# include <algorithm>
# include <string.h>

using namespace std;

int n,m,a;
int ans,as=1;
int r1[40009];

void add(int x,int l,int r,int z)
{
	r1[z]++;
	
	if(l==r)
		return ;
	
	else if(x <= (l+r)/2)
		add(x,l,(l+r)/2,z*2);
	else
		add(x,(l+r)/2+1,r,z*2+1);
}

int query(int x,int l,int r,int z)
{
	if(l == r)
		return r1[z];
	
	else if(x <= (l+r)/2)
		return query(x,l,(l+r)/2,z*2)+r1[z*2+1];
	
	else
		return query(x,(l+r)/2+1,r,z*2+1);
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int h=0; h<m; h++)
	{
		int p=0;
		
		memset(r1,0,sizeof(r1));
		
		for(int j=0; j<n; j++)
			scanf("%d",&a),p+=query(a,1,n,1),add(a,1,n,1);
		
		if(ans<p)
			as=h+1,ans=p;
	}
	
	printf("%d",as);
}
