# include <stdio.h>
# include <string.h>
# include <algorithm>

# define ma(x,y) (x>y ? x : y)

using namespace std;

int t, ans;
int geta[12][12], getb[21][12], pos[3][5];
char s[21][12];

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		ans = 0;
		memset(geta, -1, sizeof(geta));
		memset(getb, -1, sizeof(getb));
		
		pos[0][0] = -1; pos[1][0] = -1;
		
		for(int h=0; h<8; h++)	scanf("%s",s[h]);
		
		for(int h=0; h<8; h++)
			for(int j=0; j<8; j++)
				if(s[h][j] == 'K')
				{
					if(pos[0][0] == -1)	pos[0][0] = h, pos[0][1] = j;
					else 	pos[1][0] = h, pos[1][1] = j;
				}
		
		for(int h=0; h<8; h++)
		for(int j=0; j<8; j++)
		if(s[h][j] != '#'  &&  abs(pos[0][0] - h)%2==0  &&  abs(pos[0][1] - j)%2==0  &&  abs(abs(pos[0][0]-h)-abs(pos[0][1]-j))%4==0)
			geta[h][j] = (ma(abs(pos[0][0]-h), abs(pos[0][1]-j))/2)%2;
		
		for(int h=0; h<8; h++)
		for(int j=0; j<8; j++)
		if(s[h][j] != '#'  &&  abs(pos[1][0] - h)%2==0  &&  abs(pos[1][1] - j)%2==0  &&  abs(abs(pos[1][0]-h)-abs(pos[1][1]-j))%4==0)
			getb[h][j] = (ma(abs(pos[1][0]-h), abs(pos[1][1]-j))/2)%2;
		
		for(int h=0; h<8; h++)
			for(int j=0; j<8; j++)
				if(geta[h][j] != -1  &&  geta[h][j] == getb[h][j])	ans = 1;
		
		if(ans)	printf("YES\n");
		else 	printf("NO\n");
	}
}
