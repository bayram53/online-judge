# include <stdio.h>
# include <string.h>
# include <algorithm>

# define MAXN 5009

using namespace std;

int n;

int a[MAXN], b[MAXN];
char c[MAXN];

int D[MAXN*2], sz;
bool w[MAXN*2];

int b_s(int l,int r,int x)
{
	if(r-l < 2)
	{
		if(D[l] == x)	return l;
		return r;
	}
	
	int mi = (l+r)/2;
	
	if(D[mi] < x)	return b_s(mi+1, r, x);
	
	return b_s(l, mi, x);
}

int main()
{
	D[sz++] = 0;
	D[sz++] = 1000000000;
	
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%d %d %c",&a[h],&b[h],&c[h]);
		D[sz++] = a[h];
		D[sz++] = b[h];
	}
	
	sort(D, D+sz);
	
	/*int sz1 = 1;
	
	for(int h=1; h<sz; h++)
		if(D[h] != D[sz1-1])
			D[sz1++] = D[h];
	
	sz = sz1;*/
	
	//memset(w, 0, sizeof(w));
	
	for(int h=0; h<n; h++)
	{
		int pos = b_s(0, sz-1, a[h]);
		
		bool cl = (c[h] == 'w' ? 0 : 1);
		
		while(D[pos] != b[h])
		{
			w[pos++] = cl;
		}
	}
	
	int ans = 0, x, y;
	
	int cur_x, cur = 0;
	
	for(int h=0; h+1<sz; h++)
	{
		if(!w[h])
		{
			if(!cur) cur_x = D[h];
			cur += D[h+1] - D[h];
			
			if(ans < cur)
			{
				ans = cur;
				x = cur_x;
				y = D[h+1];
			}
		}
		
		else 	cur = 0;
	}
	
	printf("%d %d",x,y);
	
	/*for(int h=0; h<sz; h++)	printf("%d ",D[h]);printf("\n");
	for(int h=0; h<sz; h++)	printf("%d ",w[h]);*/
}
