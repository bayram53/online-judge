# include <stdio.h>
# include <algorithm>
# include <string.h>
# include <stdlib.h>

using namespace std;
FILE * fin = fopen("input.txt","r");
FILE * fout = fopen("output.txt","w");

struct mal
{
	int a,b;
};

int so (void const *x,void const *y)
{
	mal m=*(mal*)x;
	mal n=*(mal*)y;
	
	if(m.a==n.a)
	return m.b-n.b;
	else
	return m.a-n.a;
}

int n,ans=0;
mal t[600009];

int main()
{
	fscanf(fin,"%d",&n);
	
	for(int h=0; h<2*n; h++)
		fscanf(fin,"%d",&t[h].a),t[h].b=h+1;
	
	qsort(t,2*n,sizeof(mal),so);
	
	int a=0;
	for(int h=0; h<n; h++)
	{
		if(t[a].a!=t[a+1].a)
			ans=-1;
			
		a+=2;
	}
	
	if(ans==-1)
		fprintf(fout,"-1");
		
	else
	{
		a=0;
		
		for(int h=0; h<n; h++)
			fprintf(fout,"%d %d\n",t[a].b,t[a+1].b),a+=2;
	}
	
	fclose(fin);
	fclose(fout);
}
