# include <stdio.h>

int N,a,b,m,x,y;

char S[2000009];

char T[2000009];

int main()
{
	scanf("%d %s %s",&N,S,T);
	
	for(int h=0; h<2*N; h++)
	{
		if(S[h] == '1'  &&  T[h] == '1')	m++;
		else if(S[h] == '1')	a++;
		else if(T[h] == '1')	b++;
	}
	
	if(a < b)	b -= a , a = 0;
	else a -= b , b = 0;
	
	x = m%2;
	
	for(int h=m%2; h<2*1000001; h++)
	{
		if(a == b  &&  0 ==  a)	break;
		
		if(h%2 == 0  &&  a > 0) x++,a--;
		else if(h%2 == 0) b--;
		
		if(h%2 == 1  &&  b > 0)	y++,b--;
		else if(h%2 == 1) a--;
	}
	
	if(x == y)	printf("Draw");
	else if(x > y)	printf("First");
	else	printf("Second");
}
