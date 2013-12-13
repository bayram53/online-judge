# include <stdio.h>
# include <algorithm>

using namespace std;

int n,a;
int t[100000];
char c[3]; 

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&t[h]);
		
	sort(t,t+n);
	
	scanf("%s",c);
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
		scanf("%d",&a),printf("%d\n",t[a-1]);
}
