# include <stdio.h>

int n,k;

int main()
{
    scanf("%d %d",&n,&k);
    
    printf("%d",(n * (n - 1))/2-k);
}
