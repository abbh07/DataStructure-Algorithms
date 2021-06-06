//O(n!)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &v, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return;
}

void heap_permutation(vector<int> &v, int size, int n)
{
	if(size == 1)
	{
		print(v,n);
		return;
	}
	for(int i=0;i<size;i++)
	{
		heap_permutation(v,size-1,n);
		if(n%2 == 0)
		{
			swap(v[i],v[size-1]);
		}
		else
		{
			swap(v[0],v[size-1]);
		}
	}
}

int main()
{
	int arr[] = {1,2,3};
	vector<int> v(arr,arr + sizeof(arr)/sizeof(arr[0]) );
	int size = v.size();
	int n = v.size();
	heap_permutation(v,size,n);
	return 0;
}