# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <time.h>

# define MAXN 200009
# define mi(x,y) (x<y ? x : y)

//FILE * fin = fopen("in.txt","r");
//FILE * fout = fopen("out.txt","w");
//FILE * fout1 = fopen("mal.txt","w");
//FILE * fout2 = fopen("mal1.txt","w");

time_t  st = clock();

using namespace std;

int n, nr = 750, q, k;

struct mal
{
	char s[20];
	int ti;
} sq[MAXN], word[MAXN], nw[MAXN];

char w[20];

int den(char a[],char b[])
{
	int x = strlen(a);
	int y = strlen(b);
	
	if(x < y)	return 0;
	
	for(int h=0; h<y; h++)	if(a[h] != b[h])	return 0;
	
	return 1;
}

int cmp1(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return strcmp(m.s, n.s);
}

int cmp2(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	if(m.ti == n.ti)	return strcmp(m.s, n.s);
	
	return n.ti-m.ti;
}

int bs_1(int l,int r,char c[])
{
	if(r - l < 2)
	{
		if(den(word[l].s, c))	return l;
		if(den(word[r].s, c))	return r;
		return -1;
	}
	
	int mid = (l+r)/2;
	
	if(strcmp(word[mid].s, c) == -1)	return bs_1(mid, r, c);
	
	return bs_1(l, mid, c);
}

int bs_2(int l,int r,char c[])
{
	if(r - l < 2)
	{
		if(den(word[r].s, c))	return r;
		if(den(word[l].s, c))	return l;
		return -1;
	}
	
	int mid = (l+r)/2;
	
	if(strcmp(word[mid].s, c) == 1  &&  !den(word[mid].s, c))	return bs_2(l, mid, c);
	
	return bs_2(mid, r, c);
}

void add(mal a)
{
	for(int h=0; h<k; h++)
		if(nw[h].ti < a.ti  ||  (nw[h].ti == a.ti  &&  strcmp(nw[h].s, a.s) == 1))
		{
			if(k < 10)	k++;
			for(int j=k-1; j>h; j--)	nw[j] = nw[j-1];
			nw[h] = a;
			return ;
		}
	
	if(k < 10)	nw[k++] = a;
}

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)	scanf("%s %d",word[h].s,&word[h].ti);
	
	qsort(word, n, sizeof(mal), cmp1);
	
	for(int h=0; h<n; h++)	sq[h] = word[h];
	
	for(int j=n; j<n+500; j++)	sq[j].s[0] = '~', word[j].s[0] = '~', sq[j].ti = -1;
	
	for(int h=0; h*nr<n; h++)	qsort(sq+(h*nr), nr, sizeof(mal), cmp2);
	
	//for(int j=0; j<n; j++)	fprintf(fout1,"%s %d\n",sq[j].s,sq[j].ti);
	
	//for(int j=0; j<n; j++)	fprintf(fout2,"%s %d\n",word[j].s,word[j].ti);
	
	scanf("%d",&q);
	
	while(q--)
	{
		scanf("%s",w);
		
		k = 0;
		
		int a = bs_1(0, n, w);
		int b = bs_2(0, n, w);
		//printf("%d %d\n",a,b);getchar();
		if(a == -1)
		{
			if(q)	printf("\n");
			continue;
		}
		
		int x = a/nr+1;
		int y = b+1;
		bool e = 1;
		
		for(int j=x; (j+1)*nr<b; j++)
		{
			int r = j*nr;
			for(int i=r; i<r+10; i++)	add(sq[i]);
			y = (j+1)*nr;
			e = 0;
		}
		
		if(e)
			for(int h=a; h<=b; h++)
				add(word[h]);
		
		else
		{
			for(int j=a; j<mi(x*nr, b+1); j++)	add(word[j]);
			for(int j=y; j<=b; j++)	add(word[j]);
		}
		
		//for(int j=a; j<=b; j++)	add(word[j]);
		
		for(int h=0; h<k; h++)	printf("%s\n",nw[h].s);
		
		if(q)	printf("\n");
	}
	
	//printf("%lf",(clock()-st)/1000000.0);
}
