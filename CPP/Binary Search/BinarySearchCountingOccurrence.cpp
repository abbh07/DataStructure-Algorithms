//Counting occurrences of a number in an array O(logn)
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int key, bool search)
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
			if(search)//if search is true return lowest index else return highest index
				high = mid - 1;
			else
				low = mid + 1;
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
	int low = binary_search(v,key,true);
	if(low == -1)
		cout<<"Element not found!"<<endl;
	else
	{
		int high  = binary_search(v,key,false);
		cout<<"Number "<<key<<" occurs "<<high-low+1<<" times"<<endl; 
	}
	return 0;
}
