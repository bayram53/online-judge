# include <stdio.h>

int n,a,x1,y1,z1,x2,y2,z2;

int d[129][129][129];

void upd(int x,int y,int z,int k)
{
	for(int h=x; h<=n; h += h & -h)
		for(int j=y; j<=n; j += j & -j)
			for(int i=z; i<=n; i += i & -i)
				d[h][j][i] += k;
	
}

int sum(int x,int y,int z)
{
	int s = 0;
	
	for(int h=x; h>0; h -= h & -h)
		for(int j=y; j>0; j -= j & -j)
			for(int i=z; i>0; i -= i & -i)
				s += d[h][j][i];
	return s;
}

int main()
{
	scanf("%d",&n);
	
	while(1)
	{
		scanf("%d",&a);
		
		if(a == 3)	break;
		
		if(a == 2)	scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2) , x2++ , y2++ , z2++ , 
printf("%d\n",sum(x2,y2,z2)-sum(x2,y2,z1)-sum(x2,y1,z2)-sum(x1,y2,z2)-sum(x1,y1,z1)+sum(x1,y1,z2)+sum(x1,y2,z1)+sum(x2,y1,z1));
		
		else 	scanf("%d %d %d %d",&x1,&y1,&z1,&a) , x1++ , y1++ , z1++ , upd(x1,y1,z1,a);
	}
	
	//printf("\n%d",sum(1,1,1));
}
//11293−(1+5+50+10)−(100+5+10000+10)-(1000+50+10000+10)+(10)+(10+10000+5+50)
