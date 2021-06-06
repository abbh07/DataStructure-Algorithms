//Binary Search first occurrence
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int key)
{
	int low = 0;
	int high = v.size()-1;
	int mid = 0;
	int result = -1;
	while(high>=low)
	{
		mid = low + (high - low)/2;
		
		if(v[mid] == key)
		{
			result = mid;
			high = mid - 1;
		}
		else if(v[mid] > key)
			high = mid - 1;
		else if(v[mid] < key)
			low = mid + 1;
	}
	return result;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int key;
	cin>>key;
	int result = binary_search(v,key);
	if(result == -1)
		cout<<"Element not found!"<<endl;
	else
		cout<<"Element found at index "<<result<<endl;
	return 0;
}
