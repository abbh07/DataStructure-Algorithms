#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &v, int start, int end)
{
	int random_index = start + rand()%(end-start+1);
	swap(v[random_index],v[end]);
	int pivot = v[end];
	int partition_index = start;
	for(int i=start;i<end;i++)
	{
		if(v[i]<=pivot)
		{
			swap(v[i],v[partition_index]);
			partition_index++;
		}
	}
	swap(v[end],v[partition_index]);
	return partition_index;
}

void quick_sort(vector<int> &v, int start, int end)
{
	if(start<end)
	{
		int pivot_index = partition(v,start,end);
		quick_sort(v,start,pivot_index-1);
		quick_sort(v,pivot_index+1,end);
	}
}

int main()
{
	int arr[] = {9,8,7,6,2,4,1,3,5};
	vector<int> v(begin(arr),end(arr));
	int n = v.size();
	quick_sort(v,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	return 0;
}