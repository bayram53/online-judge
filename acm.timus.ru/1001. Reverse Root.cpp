# include <cstdio>
# include <iostream>
# include <math.h>

using namespace std;

long long n,len;
double op[1000000];

int main()
{
while(scanf("%lld",&n)!=EOF)
{
op[len++]=sqrt((double)n);
}

for(long long i=len-1 ; i>=0 ; i--)
{
printf("%lf\n",op[i]);
}

return 0;
}
