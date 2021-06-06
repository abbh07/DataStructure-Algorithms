#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_jumps(int *jump, int n)
{
	vector<int> t(n,INT_MAX);
	t[0] = 0;
	vector<int> location(n,INT_MAX);
	location[0] = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(i <= j+jump[j])
			{
				t[i] = min(t[i],t[j]+1);
				location[i] = min(location[i],j);
			}
		}
	}
	//Reverse Path
	int start = n-1;
	int l = t[n-1] + 1;
	while(l--)
	{
		cout<<jump[start]<<" ";
		start = location[start];
	}
	cout<<endl;
	return t[n-1];
}

int main()
{
	int jump_arr[] = {2,3,1,1,2,4,2,0,1,1};
	int n = 10;
	cout<<min_jumps(jump_arr,n)<<endl;
	return 0;
}