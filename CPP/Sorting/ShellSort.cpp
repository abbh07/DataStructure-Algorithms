	#include <iostream>

	using namespace std;

	void shellSort(int *ar, int size)
	{
		int j;
		for (int gap = size / 2; gap > 0; gap /= 2)
	  	{
	    	for (int i = gap; i < size; i++)
	    	{
	      		int temp = ar[i];
	      		for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
	      		{
	        		ar[j] = ar[j - gap];
	      		}
	      		ar[j] = temp;
	    	} 
	  	}
	}

	int main()
	{
		cout<<"Enter the number of elements:"<<endl;
		int n;
		cin>>n;
		int arr[n];
		cout<<"Enter the elements:"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		shellSort(arr,n);
		cout<<"Sorted array:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return 0;
	}