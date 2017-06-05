#include<iostream.h>
#include<conio.h>
class Stack
{
	int top;
	int item;
	int s[100];
	int max;
	public:
	void push();
	void pop();
	void display();
	Stack()
	{
		top=-1;
		max=100;
	}
};
void Stack :: push()
{
	cout<<"Enter the item.\n";
	if(top==(max-1))
	{
		cout<<"Stack is full\n";
		return;
	}
	cin>>item;
	top=top+1;
	s[top]=item;
	cout<<"\n";
}
void Stack :: pop()
{
	if(top==-1)
	{
		cout<<"Stack is empty.\n";
		return;
	}
	cout<<"This will delete the item : "<<s[top];
	cout<<"\n";
	top=top-1;
}
void Stack :: display()
{
	for(int i=0;i<=top;i++)
	cout<<s[i];
	cout<<"\n";
}
void main()
{
	clrscr();getch();
	cout<<"Press any key to start.\n";
	int c=0;
	Stack obj;
	while(c!=4)
	{
		cout<<"Enter 1 for push\nEnter 2 for display\nEnter 3 for pop\nEnter 4 for exit.\n";
		cin>>c;
		switch(c)
		{
			case 1:obj.push();break;
			case 2:obj.display();break;
			case 3:obj.pop();break;
			case 4:clrscr();break;
		}
	}
}