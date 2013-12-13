# include <stdio.h>

int n,x,y;
char c[3];
int t[109];

int main()
{
	scanf("%d",&n);
	
	for(int h=0; h<n; h++)
	{
		scanf("%s",c);
		x=c[0]-96; y=c[1]-48;
		if(x-2>0 && y-1>0) t[h]++;
		if(x-2>0 && y+1<9) t[h]++;
		if(x+2<9 && y-1>0) t[h]++;
		if(x+2<9 && y+1<9) t[h]++;
		if(x-1>0 && y-2>0) t[h]++;
		if(x-1>0 && y+2<9) t[h]++;
		if(x+1<9 && y-2>0) t[h]++;
		if(x+1<9 && y+2<9) t[h]++;
		
	}
	
	for(int h=0; h<n; h++)
	printf("%d\n",t[h]);
	getchar(); getchar();
}
