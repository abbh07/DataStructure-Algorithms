#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comparator
{
	bool operator() (int i, int j)
	{
		return i>j;
	}
};

int kth_smallest_minheap(int *v, int k, int n)
{
	priority_queue<int, vector<int>, comparator > minheap;

	for(int i=0;i<n;i++)
	{
		minheap.push(v[i]);
	}
	for(int i=0;i<k-1;i++)
	{
		minheap.pop();
	}
	return minheap.top();
}

int kth_smallest_maxheap(int *v, int k, int n)
{
	priority_queue<int, vector<int> > maxheap;
	for(int i=0;i<k;i++)
	{
		maxheap.push(v[i]);
	}
	for(int i=k;i<n;i++)
	{
		if(v[i] < maxheap.top())
		{
			maxheap.pop();
			maxheap.push(v[i]);
		}
	}
	return maxheap.top();
}

int main()
{
	priority_queue<int, vector<int> > maxheap;
	int v[] = {7,10,4,3,20,15};
	int n = sizeof(v)/sizeof(v[0]);
	int k = 4;
	int res = kth_smallest_minheap(v,k,n);
	//int res = kth_smallest_maxheap(v,k,n);
	cout<<res<<endl;
	return 0;
}