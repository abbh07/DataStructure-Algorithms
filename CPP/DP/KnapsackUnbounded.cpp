#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack_unbounded(int *weight, int *value, int capacity, int n)
{
	vector<int> t(capacity+1);

	for(int i=1;i<=capacity;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(weight[j]<=i)
			{
				t[i] = max(t[i], t[i-weight[j]]+value[j]);
			}
		}
	}
	return t[capacity];
}

int main()
{
	int weight[] = {5,10,15};
	int value[] = {10,30,20};
	int capacity = 100;
	int n = sizeof(value)/sizeof(value[0]);
	cout<<knapsack_unbounded(weight,value,capacity,n)<<endl;
	return 0;
}