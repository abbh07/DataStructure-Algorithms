//Binary Search Recursive
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int low, int high, int key)
{
	if(low > high)
		return -1;
	int mid = low + (high - low)/2;
	
	if(v[mid] == key)
		return mid;
	else if(v[mid] > key)
		return binary_search(v,low,mid-1,key);
	else if(v[mid] < key)
		return binary_search(v,mid+1,high,key);
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
	int result = binary_search(v,0,n-1,key);
	if(result == -1)
		cout<<"Element not found!"<<endl;
	else
		cout<<"Element found at index "<<result<<endl;
	return 0;
}
