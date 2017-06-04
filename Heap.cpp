#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int smallest = 0;
int largest = 0;

void max_heapify(vector<int> &v, int i, int *n)
{
	int left = 2*i;
	int right = 2*i+1;
	if(left <= *n && v[left] > v[i])
		largest = left;
	else
		largest = i;
	if(right <= *n && v[right] > v[largest])
		largest = right;
	if(largest != i)
	{
		swap(v[i],v[largest]);
		max_heapify(v,largest,n);
	}
}

void min_heapify(vector<int> &v, int i, int *n)
{
	int left = 2*i;
	int right = 2*i+1;
	if(left <= *n && v[left] < v[i])
		smallest = left;
	else 
		smallest = i;
	if(right <= *n && v[right] < v[smallest])
		smallest = right;

	if(smallest != i)
	{
		swap(v[i],v[smallest]);
		min_heapify(v,smallest,n);
	}
}

void build_minheap(vector<int> &v, int *size)
{
	for(int i=(*size)/2;i>=1;i--)
	{
		min_heapify(v,i,size);
	}
}

void build_maxheap(vector<int> &v, int *size)
{
	for(int i = (*size)/2;i>=1;i--)
	{
		max_heapify(v,i,size);
	}
}

void heap_sort(vector<int> &v, int *size)
{
	int n = *size;
	build_maxheap(v,size);
	for(int i=n;i>=2;i--)
	{
		swap(v[1],v[i]);
		n--;
		max_heapify(v,1,&n);
	}
}

int main()
{
	cout<<"Enter the number of elements to store in the heap"<<endl;
	int size;
	cin>>size;
	vector<int> heap(size+1);
	for(int i=1;i<=size;i++)
	{
		cin>>heap[i];
	}

	cout<<"Heap Sort:"<<endl;
	heap_sort(heap,&size);
	for(int i=1;i<=size;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;

	cout<<"Max Heap:"<<endl;
	build_maxheap(heap, &size);
	for(int i=1;i<=size;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Min Heap:"<<endl;
	build_minheap(heap, &size);	
	for(int i=1;i<=size;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	return 0;
}