#include<iostream.h>
#include<conio.h>

class Base
{
	public:
	int top;
	int remainder;
	int count;

	int arr[100];

	Base()
	{
	count=0;
	top=-1;
	}

	void pop()
	{
		if(arr[top--]<10)
		{
		cout<<arr[top];
		}

		else if(arr[top--]==10)
		{
		cout<<"A";
		}
		else if(arr[top--]==11)
		{
		cout<<"B";
		}
		else if(arr[top--]==12)
		{
		cout<<"C";
		}
		else if(arr[top--]==13)
		{
		cout<<"D";
		}
		else if(arr[top--]==14)
		{
		cout<<"E";
		}
		else if(arr[top--]==15)
		{
		cout<<"F";
		}
	}

	void push(int f,int n,int remainder)
	{
	    if(f<n)
	    {
	    arr[++top]=f;
	    }
	    else
	    {
	    arr[++top]=remainder;
	    }

	}
	void loop(int f, int n)
	{
		while(f>=n)
		{
		remainder=f%n;
		push(f,n,remainder);
		f=f/n;
		count++;
		}
		if(f<n)
		{
		count++;
		push(f,n,remainder);
		}
	}
	void display()
	{
		while(top>0)
		{
		pop();
		}
	}

};

void main()
{
	clrscr();
	int f;
	int base;
	Base obj;
	cout<<"Enter the number: ";
	cin>>f;
	cout<<"Enter the base: ";
	cin>>base;

	obj.loop(f,base);
	obj.display();

getch();
}





