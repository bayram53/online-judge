# include <stdio.h>
# include <algorithm>

using namespace std;

int n,a,b,ans,x,y;

int s[10][3] , dx[1000009] , dy[1000009];

int px[8] , py[8] , tx[8] , ty[8];

int main()
{
	for(int h=0; h<8; h++)
		scanf("%d %d",&s[h][0],&s[h][1]) , dx[s[h][0]]++ , dy[s[h][1]]++;
	
	for(int h=0; h<1000001; h++)
	{
		if(dx[h])	px[a] = dx[h] , tx[a++] = h;
		if(dy[h])	py[b] = dy[h] , ty[b++] = h;
	}
	
	if(px[0] == 3  &&  px[1] == 2  &&  px[2] == 3  &&  py[0] == 3  &&  py[1] == 2  &&  py[2] == 3)
	{
		int p = 1;
		
		for(int j=0; j<8; j++)
			if(tx[1] == s[j][0]  &&  ty[1] == s[j][1])
				p = 0;
		
		for(int i=0; i<3; i++)
		for(int i1=0; i1<3; i1++)
			{
				int k = 0;
				if(i1 == 1  &&  i == 1)	continue;
				for(int j=0; j<8; j++)
					if(tx[i1] == s[j][0]  &&  ty[i] == s[j][1])
						k++;
				if(k != 1)	p = 0;
			}
		
		if(p)	printf("respectable");
		else 	printf("ugly");
	}
	
	else 	printf("ugly");
}
