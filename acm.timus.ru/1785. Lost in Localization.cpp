# include <stdio.h>

int n;

int main()
{
	scanf("%d",&n);
	
	if(n<5) printf("few");
	else if(n>=5 && n<=9) printf("several");
	else if(n>9 && n<20) printf("pack");
	else if(n>19 && n<50) printf("lots");
	else if(n>49 && n<100) printf("horde");
	else if(n>99 && n<250) printf("throng");
	else if(n>249 && n<500) printf("swarm");
	else if(n>499 && n<1000) printf("zounds");
	else printf("legion");
	
}
