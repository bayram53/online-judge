# include <stdio.h>
# define mi(x,y) (x<y ? x : y)

int N,K,m;

char S[300009];

int ma[300009];

int main()
{
	scanf("%d %d",&N,&K);
	
	scanf("%s",S);
	
	for(int h=0; h<N; h++)
	{
		if(S[h] == '.')	m = h;
		ma[h] = m;
	}
	
	m = ma[mi(N-1,K)];
	
	for(int h=1; h<N; h++)
		if(S[h] == '.'  &&  m >= h)	m = ma[mi(N-1,h+K)];
	
	if(m == N-1)	printf("YES");
	else printf("NO");
}
