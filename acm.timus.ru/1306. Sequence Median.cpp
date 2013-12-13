# include <iostream>
# include <queue>
# include <cstdio>
# include <algorithm>

using namespace std;

int n,temp;
double res;
priority_queue<int> pq;

int main()
{
	cin>>n;
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>temp;
		
		pq.push(temp);
		
		if( i>n/2 )
		pq.pop();
	}
	
	if(n%2==0)
	{
		res=pq.top();
		pq.pop();
		res+=pq.top();
		res/=2;
	}
	else
	{
		//pq.pop();
		res=pq.top();
	}
	
	printf("%.1lf",res);
	
	return 0;
}
