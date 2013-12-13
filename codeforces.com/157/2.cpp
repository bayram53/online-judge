# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

using namespace std;

int n;
int t[5][5];

int barla()
{
	int a=t[0][0]+t[1][1]+t[2][2];
	
	if(a==t[0][0]+t[0][1]+t[0][2] && a==t[1][0]+t[1][1]+t[1][2] && a==t[2][0]+t[2][1]+t[2][2] &&
	t[0][2]+t[1][1]+t[2][0]==a && a==t[0][0]+t[1][0]+t[2][0] && a==t[0][1]+t[1][1]+t[2][1] && a==t[0][2]+t[1][2]+t[2][2])
		return 0;
		
	return 1;
	
}

int main()
{
	for(int h=0; h<3; h++)
		for(int j=0; j<3; j++)
			scanf("%d",&t[h][j]);
			
	for(int h=0; h<100009; h++)
	{
		t[0][0]=h;
		t[1][1]=t[1][0]+t[2][0]+h-t[0][1]-t[2][1];
		t[2][2]=t[1][0]+t[2][0]+h-t[0][2]-t[1][2];
		
		if(barla()==0){
			for(int j=0; j<3; j++){
				for(int k=0; k<3; k++)
					printf("%d ",t[j][k]);printf("\n");}
					return 0;
				}
	}
	
	
}
