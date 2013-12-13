# include <stdio.h>
# include <string.h>

int n, a;
int D[4009], V[36089], l;
long long ans;
char s[4009];

int main()
{
	scanf("%d %s",&a,s);
	
	n = strlen(s);
	
	for(int h=1; h<=n; h++)
		{D[h] = s[h-1]-'0'; D[h] += D[h-1];}
	
	for(int h=1; h<=n; h++)
		for(int j=h; j<=n; j++)
			V[D[j]-D[h-1]]++, l++;
	
	for(int h=1; h<=n; h++)
		for(int j=h; j<=n; j++)
		{
			int k = D[j] - D[h-1];
			if(!a)
			{
				if(k) ans += V[0];
				else 	ans += l;
				continue;
			}
			if(!k  ||  36005 < a/k)	continue;
			if(a%k == 0)	ans += (long long)V[a/k];
		}
	
	printf("%I64d\n",ans);
}
