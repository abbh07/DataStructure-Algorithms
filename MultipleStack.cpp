#include <iostream>
#include <cstdlib>
const int arrsize = 20;

using namespace std;

class MultipleStack
{
private:
	int arr[arrsize];
	int top[arrsize/2];
	int temp[arrsize/2];
public:
	void push();
	int pop();
	void display();
	void create (int);
};

void MultipleStack::push()
{
	cout<<"Enter the stack number\n";
	int s;
	cin>>s;
	cout<<"Enter the element\n";
	int ele;
	cin>>ele;
	if(top[s-1]==temp[s])
	{
		cout<<"Stack Overflow!\n";
	}
	else
	{
		arr[++top[s-1]]=ele;
	}
}

int MultipleStack::pop()
{
	cout<<"Enter the stack number\n";
	int s;
	cin>>s;
	if(top[s-1]==temp[s-1])
	{
		return -1;
	}
	else
	{
		return arr[top[s-1]--];
	}
}

void MultipleStack::display()
{
	cout<<"Enter the stack number\n";
	int s;
	cin>>s;
	if(top[s-1]==temp[s-1])
        cout<<"Stack Empty!\n";
	for(int i=temp[s-1]+1;i<=top[s-1];i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void MultipleStack::create(int n)
{
	for(int i=0;i<n;i++)
	{
		top[i]=temp[i]=(arrsize/n)*i-1;
	}
	temp[n]=arrsize-1;
}

int main()
{
	MultipleStack m;
	cout<<"Enter the number of stacks you want to create\n";
	int n;
	cin>>n;
	m.create(n);
	int ele;
	while(1)
	{
		cout<<"1.Push 2.Pop 3.Display 4.Exit\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:m.push();
				   break;
		 	case 2: ele = m.pop();
		 			if(ele==-1)
		 			{
		 				cout<<"Stack Underflow!\n";
		 			}
		 			else
		 			{
		 				cout<<"Popped element = "<<ele<<endl;
		 			}
		 			break;
		 	case 3:m.display();
		 	       break;
		 	case 4:exit(0);

		}
	}
	return 0;
}
