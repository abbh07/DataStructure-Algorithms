#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout<<"Enter the length of the array"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int val = 0;
	int max = 0;
	/*
	* Kadane's Algorithm
	* This code is not valid for an array with all negative elements.
	* For an array with all negative elements, the maximum sum is the largest negative number in the array.
	*/ 
	for(int i=0;i<n;i++)
	{
		val += arr[i];
		if(val < 0)
		{
			val = 0;
		}
		if(val > max)
		{
			max = val;
		}
	}
	cout<<"Maximum sub-array sum = "<<max<<endl;
	return 0;
}