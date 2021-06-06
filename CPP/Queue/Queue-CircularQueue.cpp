#include <iostream>
#include <cstdlib>
#define size 20

using namespace std;

class CircularQueue
{
private:
	int front,rear,count;
	int arr[size];
public:
	CircularQueue()
	{
		front=rear=count=0;
	}
	void enqueue();
	void dequeue();
	void display();
};

void CircularQueue::enqueue()
{
	if(count==size)
	{
		cout<<"Queue Full!\n";
	}
	else
	{
		cout<<"Enter the element to be inserted\n";
		int ele;
		cin>>ele;
		rear=(rear+1)%size;
		arr[rear]=ele;
		count++;
	}
}

void CircularQueue::dequeue()
{
	if(count==0)
		cout<<"Queue Empty!\n";
	else
	{
		front=(front+1)%size;
		cout<<"Item dequeued: "<<arr[front]<<endl;
		count--;
	}
}

void CircularQueue::display()
{
	if(count==0)
		cout<<"Queue Empty!\n";
	else
	{
		int k=front+1;
		cout<<"Elements: \n";
		for(int i=0;i<count;i++)
		{
			cout<<arr[k]<<"\t";
			k=(k+1)%size;
		}
		cout<<endl;

	}
}

int main()
{
	CircularQueue cq;
	while(1)
	{
		cout<<"1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:cq.enqueue();
					break;
			case 2:cq.dequeue();
					break;
			case 3:cq.display();
					break;
			case 4:exit(0);

		}
	}
	return 0;
}
