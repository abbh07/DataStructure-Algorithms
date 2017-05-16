//How many times a circular array is rotated? 
#include <iostream>
#include <vector>

using namespace std;

int find_rotation_count(vector<int> v)
{
	int low = 0;
	int n = v.size();
	int high = n-1;
	int mid = 0;
	while(high >= low)
	{
		mid = low + (high - low)/2;
		
		if(v[low] <= v[high])
			return low;
		int next = (mid+1)%n;
		int prev = (mid-1+n)%n;
		
		if(v[mid] <= v[next] && v[mid] <= v[prev])
			return mid;
			
		if(v[mid] <= v[high])
			high = mid - 1;
		if(v[mid] >= v[low])
			low = mid + 1;
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
	int result = find_rotation_count(v);
	if(result != -1)
		cout<<"The array is rotated "<<result<<" times "<<endl;
	
	return 0;
}
