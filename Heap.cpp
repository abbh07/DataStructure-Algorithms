#include <iostream>

using namespace std;

//Min Heap
class Heap
{
private:
	int *arr;
	int heapSize;
	int arrSize;
public:
	Heap(int size)
	{
		arr = new int[size];
		heapSize = 0;
		arrSize = size;
	}
	int getLeftChildIndex(int);
	int getRightChildIndex(int);
	int getParentIndex(int);
	int getMinimum();
	bool isEmpty();
	void heapifyUp(int);
	void insert(int);
	void heapifyDown(int);
	void removeMinimum();
	void display();
	~Heap()
	{
		delete [] arr;
	}

};

int Heap::getLeftChildIndex(int nodeIndex)
{
	return (2*nodeIndex+1);
}

int Heap::getRightChildIndex(int nodeIndex)
{
	return (2*nodeIndex+2);
}

int Heap::getParentIndex(int nodeIndex)
{
	return ((nodeIndex-1)/2);
}

int Heap::getMinimum()
{
	if(isEmpty())
	{
		cout<<"Heap Empty!\n";
		return -1;		
	}
	else
		return arr[0];
}

bool Heap::isEmpty()
{
	if(heapSize == 0)
	return true;
	else
	return false;	
}

void Heap::heapifyUp(int nodeIndex)
{
	int parentIndex;
	int temp;
	if(nodeIndex != 0)
	{
		parentIndex = getParentIndex(nodeIndex);
	}
	while(nodeIndex != 0 && arr[parentIndex]>arr[nodeIndex])
	{
		temp = arr[nodeIndex];
		arr[nodeIndex] = arr[parentIndex];
		arr[parentIndex] = temp;
		nodeIndex = parentIndex;
		parentIndex = getParentIndex(nodeIndex);
	}
}

void Heap::insert(int val)
{
	if(heapSize == arrSize)
		cout<<"Heap Full!\n";
	else
	{
		heapSize++;
		arr[heapSize-1] = val;
		heapifyUp(heapSize-1);
	}
}

void Heap::heapifyDown(int nodeIndex)
{
	int leftChildIndex = getLeftChildIndex(nodeIndex);
	int rightChildIndex = getRightChildIndex(nodeIndex);
	int minIndex;
	if(rightChildIndex >= arrSize)
	{
		if(leftChildIndex >= arrSize)
			return;
		else
			minIndex = leftChildIndex;
	}
	else
	{
		if(arr[leftChildIndex] <= arr[rightChildIndex])
			minIndex = leftChildIndex;
		else
			minIndex = rightChildIndex;
	}
	int temp;
	if(arr[nodeIndex] > arr[minIndex])
	{
		temp = arr[nodeIndex];
		arr[nodeIndex] = arr[minIndex];
		arr[minIndex] = temp;
		heapifyDown(minIndex);
	}
}

void Heap::removeMinimum()
{
	if(isEmpty())
	{
		cout<<"Heap Empty!\n";
		return;
	}
	else
	{
		arr[0] = arr[heapSize-1];
		heapSize--;
		arrSize--;
		if(heapSize > 0)
			heapifyDown(0);
	}
}

void Heap::display()
{
	for(int i=0;i<arrSize;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
	cout<<"Enter the size of the array\n";
	int n;
	cin>>n;
	Heap h(n);
	cout<<"Enter the elements of the array\n";
	int val;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		h.insert(val);
	}
	cout<<"Min Heap:\n";
	h.display();	
	cout<<"Min Heap after removing the minimum element:\n";
	h.removeMinimum();
	h.display();	
	return 0;
}