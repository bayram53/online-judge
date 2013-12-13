# include <stdio.h>

int ans[50090];
int t[]={10,50,100,500,1000,5000};
int san[10],n,m=0,kici=-1,toplam=0,a,k;

int main()
{
	for(int h=0; h<6; h++)
	{
		scanf("%d",&san[h]);
		
		toplam+=t[h]*san[h];
		
		if(kici==-1 && san[h]!=0)
			kici=t[h];
	}
	
	a=toplam;
	
	scanf("%d",&n);
	
	k=(toplam-kici)/n;
	
	a=(toplam-kici)+(n-(toplam-kici)%n);
	k++;
	
	while(toplam>=a)
	{
		ans[m++]=a;
		a+=n;
	}
	
	printf("%d\n",m);
	
	for(int h=0; h<m; h++)
		printf("%d ",ans[h]/n);
}
