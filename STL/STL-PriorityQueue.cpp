#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comparator 
{
	bool operator()(int i, int j)
	{
		return i>j;
	}
};

int main()
{
	priority_queue<int, vector<int> > maxheap;
	priority_queue<int, vector<int>, comparator> minheap;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int value;
		cin>>value;
		maxheap.push(value);
		minheap.push(value);
	}
	cout<<"Max Heap elements:"<<endl;
	while(!maxheap.empty())
	{
		cout<<maxheap.top()<<" ";
		maxheap.pop();
	}
	cout<<endl;
	cout<<"Min Heap elements:"<<endl;
	while(!minheap.empty())
	{
		cout<<minheap.top()<<" ";
		minheap.pop();
	}
	cout<<endl;
	return 0;
}