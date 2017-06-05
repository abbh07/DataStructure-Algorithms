#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_01(vector<int> &weight, vector<int> &value, int nitems, int capacity)
{
	vector< vector<int> > T(nitems+1, vector<int>(capacity+1));
	for(int i=0;i<=nitems;i++)
	{
		for(int j=0;j<=capacity;j++)
		{
			if(i==0 || j==0)
			{
				T[i][j] = 0;
			}
			else if(j < weight[i-1])
			{
				T[i][j] = T[i-1][j];
			}
			else
			{
				T[i][j] = max( T[i-1][j], value[i-1] + T[i-1][j-weight[i-1]] );
			}
		}
	}
	return T[nitems][capacity];
}

int main()
{
	cout<<"Enter number of items:"<<endl;
	int n;
	cin>>n;
	vector<int> weight(n);
	vector<int> value(n);
	cout<<"Enter the weights and values for the items:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>weight[i]>>value[i];
	}
	cout<<"Enter the capacity:"<<endl;
	int capacity;
	cin>>capacity;
	cout<<"The maximum possible value: "<<knapsack_01(weight, value, n, capacity)<<endl;
	return 0;
}