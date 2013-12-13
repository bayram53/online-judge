# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

FILE * fin = fopen("input.txt","r");
FILE * fout = fopen("output.txt","w");

int n,ans=0;
char c1[100009],c2[100009];
int t1[30][100009];
int t2[100009];

int main()
{
	fscanf(fin,"%s\n%s",c1,c2);
	
	n=strlen(c1);
	
	for(int h=0; h<n; h++)
	{
		t1[c1[h]-65][0]++;
		t1[c1[h]-65][100008]++;
		t1[c1[h]-65][t1[c1[h]-65][0]]=h;
		
		t2[c2[h]-65]++;
	}
	
	for(int h=0; h<30; h++)
	{
		if(t1[h][0]==t2[h])
			t1[h][0]=0,t2[h]=0;
		
		else if(t1[h][0]>t2[h])
			t1[h][0]-=t2[h],t2[h]=0;
			
		else
			t2[h]-=t1[h][0],t1[h][0]=0;	
	}
	
	
	for(int h=0; h<30; h++)
		ans+=t1[h][0];
	
	fprintf(fout,"%d\n",ans);
	
	int a=29,a1=0,b,b1,c=1,d;
	
	b=t1[0][0];
	b1=t2[0];
	d=t1[0][100008];
	
	while(ans!=0)
	{
		if(b==0)
			{a--;b=t1[a][0];c=1;d=t1[a][100008];continue;}
		
		if(b1==0)
			{a1++;b1=t2[a1];continue;}
		
		if(a<a1)
			c1[t1[a][d]]=char(a1+65),d--;
		
		else
			{c1[t1[a][c]]=char(a1+65);c++;}
		
		b--;
		b1--;
		ans--;
	}
	
	fprintf(fout,"%s",c1);
	
	fclose(fin);
	fclose(fout);
}
