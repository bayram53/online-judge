# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;

FILE * fin = fopen("input.txt","r");
FILE * fout = fopen("output.txt","w");

int n,ans=0,o=0;
int day[1000];
int mo[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d,t,p,m;
int main()
{
	fscanf(fin,"%d",&n);
	
	for(int h=0; h<n; h++)
	{
		fscanf(fin,"%d %d %d %d",&m,&d,&p,&t);
		
		int p1=0;
		
		for(int h=1; h<m; h++)
			p1+=mo[h];
		
		p1+=d;
		day[p1+200]+=p;
		day[p1+200-t]+=-p;
	}
	
	for(int h=0; h<1000; h++)
	{
		o+=day[h];
		
		if(o<ans)
			ans=o;
	}
	
	fprintf(fout,"%d",abs(ans));
	
	fclose(fin);
	fclose(fout);
}
