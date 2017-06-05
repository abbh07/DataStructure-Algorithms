#include<iostream.h>
#include<conio.h>
#define max 20
#define max_s 10
#include<process.h>
class mul_stack
{	int s[max];
	int b[max_s],top[max_s];
	public:
	void push();
	int pop();
	void display();
	void createstack(int);
};
void mul_stack::push()
{	int i,item;
	cout<<"Enter the stack number you want to insert"<<endl;
	cin>>i;
	cout<<"Enter the item to be inserted : ";
	cin>>item;
	if(top[i-1]==b[i])
	{	cout<<"Stack number "<<i<<" is full"<<endl;
		return;
	}
	s[++top[i-1]]=item;
}
int mul_stack::pop()
{	int i;
	cout<<"Enter the stack number "<<endl;
	cin>>i;
	if(top[i-1]==b[i-1])
		return -1;
	else
		return s[top[i-1]--];
}
void mul_stack::display()
{	int i;
	cout<<"Enter the stack no : ";
	cin>>i;
	if(top[i-1]==b[i-1])
	{	cout<<"Stack no "<<i<<" is empty";
		return;
	}
	cout<<"Contents of Stack "<<i<<" are"<<endl;
	for(int k=b[i-1]+1;k<=top[i-1];k++)
	cout<<s[k]<<"  ";
}
void mul_stack::createstack(int n)
{	for(int j=0;j<n;j++)
	{	b[j]=top[j]=max/n*j-1;
		cout<<b[j]<<"\t"<<top[j]<<endl;
	}b[n]=max-1;
}
void main()
{	mul_stack ms;
	int ch,n,item,j;
	clrscr();
	cout<<"\nEnter number of stacks";
	cin>>n;
	ms.createstack(n);
	for(;;)
	{	cout<<"\nStack no: ";
		for(j=1;j<=n;j++)
		cout<<j<<"\t";
		cout<<"\n1 Push"<<endl<<"2 Pop"<<endl<<"3 Display"<<endl<<"4 exit";
		  cin>>ch;
		switch(ch)
			{	case 1 : ms.push();
					 break;
				case 2 : item=ms.pop();
					 if(item==-1)
					 cout<<"stack is empty";
					 else
					 cout<<"deleted item :"<<item;
					 break;
				case 3 : ms.display();
					 break;
				case 4 : exit(0);

			}
	}
	getch();
}