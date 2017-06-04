#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 10

using namespace std;

class PriorityQueue
{
private:
	int size = 0;
	int largest = 0;
public:
	void max_heapify(vector<int> &, int);
	int maximum(vector<int> &);
	int extract_maximum(vector<int> &);
	void increase_value(vector<int> &, int, int);
	void insert_value(vector<int> &, int);
	void print(vector<int> &);
};

void PriorityQueue::max_heapify(vector<int> &v, int i)
{
	int left = 2*i;
	int right = 2*i+1;
	if(left <= size && v[left] > v[i])
		largest = left;
	else
		largest = i;
	if(right <= size && v[right] > v[largest])
		largest = right;
	if(largest != i)
	{
		swap(v[i],v[largest]);
		max_heapify(v,largest);
	}
}

int PriorityQueue::maximum(vector<int> &v)
{
	if(size == 0)
	{
		return INT_MIN;
	}
	return v[1];
}

int PriorityQueue::extract_maximum(vector<int> &v)
{
	if(size == 0)
	{
		return INT_MIN;
	}
	int max_ele = v[1];
	v[1] = v[size];
	size--;
	max_heapify(v,1);
	return max_ele;
}

void PriorityQueue::increase_value(vector<int> &v, int i, int value)
{
	if(value < v[i])
	{
		cout<<"Value less than existing value!"<<endl;
		return;
	}
	else if(i>size)
	{
		cout<<"Invalid Index!"<<endl;
		return;
	}
	v[i] = value;
	while(i>1 && v[i/2]<v[i])
	{
		swap(v[i/2],v[i]);
		i = i/2;
	}
}

void PriorityQueue::insert_value(vector<int> &v, int value)
{
	if(size == MAX_SIZE)
	{
		cout<<"Queue Full!"<<endl;
		return;
	}
	v[++size] = INT_MIN; //Assuming all numbers are greater than INT_MIN
	increase_value(v,size,value);
}

void PriorityQueue::print(vector<int> &v)
{
	for(int i=1;i<=size;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> heap(MAX_SIZE);
	PriorityQueue pq;
	int choice, index, value, result;
	while(true)
	{
		cout<<"1 Insert 2 Maximum 3 Extract Maximum 4 Increase Value 5 Print 6 Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: 
			cout<<"Enter value to insert"<<endl;
			cin>>value;
			pq.insert_value(heap, value);
			break;

			case 2:
			result = pq.maximum(heap);
			if(result == INT_MIN)
				cout<<"Queue Empty!"<<endl;
			else
				cout<<"Maximum Value: "<<result<<endl;
			break;

			case 3:
			result = pq.extract_maximum(heap);
			if(result == INT_MIN)
				cout<<"Queue Empty!"<<endl;
			else
				cout<<"Extracted max element: "<<result<<endl;
			break;

			case 4:
			cout<<"Enter the index and the new value"<<endl;
			cin>>index>>value;
			pq.increase_value(heap,index,value);
			break;

			case 5:
			cout<<"Queue Elements:"<<endl;
			pq.print(heap);
			break;
			
			case 6:
			exit(0);

			default:
			cout<<"Invalid choice!"<<endl;
		}
	}
	return 0;
}