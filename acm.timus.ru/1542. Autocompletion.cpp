# include <stdio.h>
# include <string.h>
# include <algorithm>

# define MAXN 100009

using namespace std;

int n, q;

struct mal
{
	int ti;
	char s[16];
} T[131079][13], word[MAXN], ret[13];

int cmp(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return strcmp(m.s, n.s);
}

void gos1(int x,int y)
{
	int &k = T[x][11].ti;
	
	for(int h=0; h<k; h++)
		if(T[x][h].ti < word[y].ti  ||  (T[x][h].ti == word[y].ti  &&  strcmp(T[x][h].s, word[y].s) == 1))
		{
			if(k < 10)	k++;
			
			for(int j=k-1; j>h; j--)	T[x][j] = T[x][j-1];
			
			T[x][h] = word[y];
			return ;
		}
	
	if(k < 10)	T[x][k++] = word[y];
}

void add(int x,int l,int r,int node)
{
	if(l == r)	return;
	
	gos1(node, x);
	
	if(x <= (l+r)/2)	add(x, l, (l+r)/2, node*2);
	else 	add(x, (l+r)/2+1, r, node*2+1);
}

void gos2(mal x)
{
	int &k = ret[11].ti;
	
	for(int h=0; h<k; h++)
		if(ret[h].ti < x.ti  ||  (ret[h].ti == x.ti  &&  strcmp(ret[h].s, x.s) == 1))
		{
			if(k < 10)	k++;
			
			for(int j=k-1; j>h; j--)	ret[j] = ret[j-1];
			
			ret[h] = x;
			return ;
		}
	
	if(k < 10)	ret[k++] = x;
}

int den(char a[],char b[])
{
	int x = strlen(a);
	int y = strlen(b);
	
	if(x < y)	return 0;
	
	for(int j=0; j<y; j++)	if(a[j] != b[j])	return 0;
	
	return 1;
}

void query(char x[],int l,int r,int node)
{//printf("%s   %s , %s   %d %d\n",x,word[l].s,word[r].s,l,r);getchar();
	if(strcmp(x, word[r].s) == 1  ||  (strcmp(x, word[l].s) == -1  &&  !den(word[l].s, x)))	return ;
	
	if(den(word[l].s, x)  &&  den(word[r].s, x))
	{
		if(l == r)	gos2(word[l]);
		
		else
			for(int j=0; j<T[node][11].ti; j++)
				gos2(T[node][j]);
		return ;
	}
	
	query(x, l, (l+r)/2, node*2);
	query(x, (l+r)/2+1, r, node*2+1);
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<131079; h++)	T[h][11].ti = 0;
	
	for(int h=1; h<=n; h++)	scanf("%s %d",word[h].s,&word[h].ti);
	
	qsort(word+1, n, sizeof(mal), cmp);
	//for(int h=1; h<=n; h++)	printf("%d  :  %s %d\n",h,word[h].s,word[h].ti);
	for(int h=1; h<=n; h++)	add(h, 1, n, 1);
	
	scanf("%d",&q);
	
	while(q--)
	{
		char p[20];
		
		scanf("%s",p);
		
		ret[11].ti = 0;
		
		query(p, 1, n, 1);
		
		for(int h=0; h<ret[11].ti; h++)	printf("%s\n",ret[h].s);
		
		if(q)	printf("\n");
	}
}
