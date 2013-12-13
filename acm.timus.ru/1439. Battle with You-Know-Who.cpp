# include <stdio.h>

# define MAXN 10009
# define ma(x,y) (x>y ? x : y)
# define geth(x) (H[x] = ma(H[LC], H[RC])+1)
# define son(x) (C[x] = C[L[x]]+C[R[x]]+1)
# define LC L[node]
# define RC R[node]

int n, sz, k, tmp, root, po[34];
int D[MAXN], H[MAXN], L[MAXN], R[MAXN], C[MAXN];

int rot_left(int node)
{
	tmp = RC;
	RC = L[RC]; L[tmp] = node;
	geth(node), son(node);
	geth(tmp), son(tmp);
	return tmp;
}

int rot_right(int node)
{
	tmp = LC;
	LC = R[LC]; R[tmp] = node;
	geth(node), son(node);
	geth(tmp), son(tmp);
	return tmp;
}

int fix(int node)
{
	geth(node), son(node);
	
	if(H[LC] > H[RC]+1)
	{
		if(H[R[LC]] > H[L[LC]])	LC = rot_left(LC);
		node = rot_right(node);
	}
	
	else if(H[LC]+1 < H[RC])
	{
		if(H[R[RC]] < H[L[RC]])	RC = rot_right(RC);
		node = rot_left(node);
	}
	
	return node;
}

int add(int node,int x)
{
	if(!node)
	{
		D[++sz] = x; C[sz] = H[sz] = 1;
		return sz;
	}
	
	if(x < D[node])	LC = add(LC, x);
	else 	RC = add(RC, x);
	
	return fix(node);
}

int sm(int node,int x)
{
	if(!node)	return 0;
	if(x < D[node])		return sm(LC, x);
	return 1 + C[LC] + sm(RC, x);
}

int bamy(int node,int x)
{
	if(!node)	return 0;
	if(D[node] == x)	return 1;
	if(x < D[node])	return bamy(LC, x);
	return bamy(RC, x);
}

void dfs(int node)
{
	if(LC)	dfs(LC);
	///printf("data :%d    left : %d    right : %d    child : %d    height : %d\n",D[node],D[LC],D[RC],C[node],H[node]);
	printf("%d ",D[node]);
	if(RC)	dfs(RC);
}

int main()
{
	po[0] = 1;
	for(int h=1; h<31; h++)	po[h] = po[h-1]*2;
	
	scanf("%d %d",&n,&k);
	
	while(k--)
	{
		char s[90];
		int a, x = 0;
		scanf("%s %d",s,&a);
		
		for(int h=30; h>-1; h--)
		{
			int e = x+po[h];
			if(sm(root, e)+a > e  ||  (sm(root, e)+a == e  &&  !bamy(root, e)))	x += po[h];
		}
		if(s[0] == 'L')	printf("%d\n",x);
		else 	root = add(root, x);
	}
}
