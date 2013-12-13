# include <stdio.h>

short int n,x1,x2,y1,y2,z1,z2,a;

int ra[255][255][255];

void add3(short int x,short int y,short int z,short int k,short int l,short int r,short int node)
{
	ra[x-1][y-1][node-1] += k;
	
	if(l == r)	return ;
	
	if(z <= (l+r)/2)	add3(x,y,z,k,l,(l+r)/2,node*2);
	
	else 	add3(x,y,z,k,(l+r)/2+1,r,node*2+1);
}

void add2(short int x,short int y,short int z,short int k,short int l,short int r,short int node)
{
	add3(x , node , z , k , 1 , n , 1);
	
	if(l == r)	return ;
	
	else if(y <= (l+r)/2)	add2(x,y,z,k,l,(l+r)/2,node*2);
	
	else 	add2(x,y,z,k,(l+r)/2+1,r,node*2+1);
}

void add1(short int x,short int y,short int z,short int k,short int l,short int r,short int node)
{
	add2(node , y , z , k , 1 , n , 1);
	
	if(l == r)	return ;
	
	else if(x <= (l+r)/2)	add1(x,y,z,k,l,(l+r)/2,node*2);
	
	else 	add1(x,y,z,k,(l+r)/2+1,r,node*2+1);
}

int query3(short int x,short int y,short int z1,short int z2,short int l,short int r,short int node)
{
	if(z1 <= l  &&  z2 >= r)	return ra[x-1][y-1][node-1];
	
	if(z2 < l  ||  z1 > r)	return 0;
	
	if(l == r)	return ra[x-1][y-1][node-1];
	
	int a = query3(x , y , z1 , z2 , l , (l+r)/2 , node*2);
	a += query3(x , y , z1 , z2 , (l+r)/2+1 , r , node*2+1);
	
	return a;
}

int query2(short int x,short int y1,short int z1,short int y2,short int z2,short int l,short int r,short int node)
{
	if(y1 <= l  &&  y2 >= r)	return query3(x , node , z1 , z2 , 1 , n , 1);
	
	if(y2 < l  ||  y1 > r)	return 0;

	if(l == r)	return query3(x , node , z1 , z2 , 1 , n , 1);
		
	int a = query2(x , y1 , z1 , y2 , z2 , l , (l+r)/2 , node*2);
	a += query2(x , y1 , z1 , y2 , z2 , (l+r)/2+1 , r , node*2+1);
	
	return a;
}

int query1(short int x1,short int y1,short int z1,short int x2,short int y2,short int z2,short int l,short int r,short int node)
{
	if(x1 <= l  &&  x2 >= r)	return query2(node , y1 , z1 , y2 , z2 , 1 , n , 1);
	
	if(x2 < l  ||  x1 > r)	return 0;
	
	if(l == r)	return query2(node , y1 , z1 , y2 , z2 , 1 , n , 1);

	int a = query1(x1 , y1 , z1 , x2 , y2 , z2 , l , (l+r)/2 , node*2);
	a += query1(x1 , y1 , z1 , x2 , y2 , z2 , (l+r)/2+1 , r , node*2+1);
	
	return a;
}

int main()
{
	scanf("%hd",&n);
	
	while(1)
	{
		scanf("%hd",&a);
		
		if(a == 3)	break;
		
		if(a == 2)	scanf("%hd %hd %hd %hd %hd %hd",&x1,&y1,&z1,&x2,&y2,&z2) , x1++ , y1++ , z1++ , x2++ , y2++ , z2++ ,
		printf("%d\n",query1(x1,y1,z1,x2,y2,z2,1,n,1));
		
		if(a == 1)	scanf("%hd %hd %hd %hd",&x1,&y1,&z1,&a) , x1++ , y1++ , z1++ , add1(x1,y1,z1,a,1,n,1);
	}
}
