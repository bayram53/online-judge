# include <stdio.h>
# include <string.h>
# include <algorithm>

# define MAXN 10009
# define mi(x,y) (x<y ? x : y)
# define sq 110

using namespace std;

struct mal
{
	char s[25];
} I[MAXN], W[MAXN], S[sq][30];
int a, n = 1, m = 1, i[MAXN], si[sq];
bool v[MAXN];
char s[25];

int cmp(void const *x,void const *y)
{
	mal m = *(mal*)x;
	mal n = *(mal*)y;
	
	return strcmp(m.s, n.s);
}

int den(char a[], char b[])
{
	int x = strlen(a);
	int y = strlen(b);
	
	if(y < x)	return 0;
	
	for(int h=0; h<x; h++)	if(a[h] != b[h])	return 0;
	
	return 1;
}

int main()
{
	
	
	W[0].s[0] = 's';
	W[0].s[1] = 'u';
	W[0].s[2] = 'n';
	
	I[0] = W[0];
	i[0] = 1;
	
	while(scanf("%s",s) != EOF)
	{
		a = strlen(s);
		
		if(s[0] == '+')
		{
			for(int h=1; h<a; h++)	W[m].s[h-1] = I[n].s[h-1] = s[h];
			i[n] = 1;
			m++;
		}
		
		else
			for(int h=1; h<a; h++)	I[n].s[h-1] = s[h];
		
		n++;
	}
	
	qsort(W, m, sizeof(mal), cmp);
	
	int k = 0;
	
	for(int h=1; h<m; h++)
		if(strcmp(W[h].s, W[k].s))
			W[++k] = W[h];
	
	m = k;
	
	for(int h=0; h<n; h++)
	{
		int l, r, q = 0;
		
		char soz[25];
		strcpy(soz, I[h].s);
		
		if(i[h])
		{
			for(int j=0; j<sq; j++)
			{
				l = sq*j;
				r = mi(m, sq*(j+1)-1);
				
				if(strcmp(soz, W[r].s) < 1)
				{
					for(int u=l; u<=r; u++)
						if(!strcmp(soz, W[u].s))
						{
							if(v[u]) q = 1;
							v[u] = 1;
							break;
						}
					
					if(q)	break;
					
					strcpy(S[j][si[j]].s, soz);
					
					for(int u=si[j]-1; u>-1 && strcmp(soz, S[j][u].s) < 0; u--)
						swap(S[j][u], S[j][u+1]);
					
					si[j]++;
					
					if(si[j] > 20)	si[j]--;
					
					break;
				}
			}
		}
		
		else
		{
			printf("%s\n",soz);
			
			for(int j=0; j<sq; j++)
			{
				l = sq*j;
				r = mi(m, sq*(j+1)-1);
				
				if(strcmp(soz, W[l].s) < 0  &&  !den(soz, W[l].s))	break;
				
				if(strcmp(soz, W[r].s) > 0)	continue;
				
				int k = den(soz, W[l].s) + den(soz, W[r].s);
				
				if(k == 2)
					for(int u=0; u<si[j] && q<20; u++)
						printf("  %s\n",S[j][u].s), q++;
				else
					for(int u=l; u<=r && q<20; u++)
						if(den(soz, W[u].s)  &&  v[u])
							printf("  %s\n",W[u].s), q++;
				
				if(q == 20)	break;
			}
			
		}
	}
}
