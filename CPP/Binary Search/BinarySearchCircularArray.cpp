//Searching an item in a circular sorted array O(log n)
#include <iostream>
#include <vector>

using namespace std;

int circular_search(vector<int> v, int key)
{
	int low = 0;
	int high = v.size()-1;
	int mid = 0;
	
	while(high>=low)
	{
		mid = low + (high - low)/2;
		
		if(v[mid] == key)
			return mid;
		else if(v[mid] <= v[high])
		{
			if(key > v[mid] && key <= v[high])
				low = mid + 1;
			else
				high  = mid - 1;
		}
		else if(v[low] <= v[mid])
		{
			if(key >= v[low] && key < v[mid])
				high = mid - 1;
			else
				low = mid + 1; 
		}
	}
	return -1;
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
	int result = circular_search(v,key);
	if(result == -1)
		cout<<"Element not found!"<<endl;
	else
		cout<<"Element found a position "<<result<<endl;
	return 0;
}