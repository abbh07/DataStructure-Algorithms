#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>

class node
{
	public:
	int constant;
	int exponent;
	node *next;
	node()
	{
	constant=0;
	exponent=0;
	next=NULL;
	}
	void insertNode(node*,int,int);
	void display(node*);
	void add(node*,node*,node*);


};


//Function to insert a node to the list.
void node::insertNode(node *head, int c, int e)
{
	node* temp = head;
	node* news = new node;
	news->next=head;
	while (temp->next != head)
		temp = temp -> next;
	temp -> next = news;
	news -> constant = c;
	news -> exponent = e;
}

//Function to display a polynomial.
void node::display(node* head)
{
	node* temp;
	temp = head;
	while(temp->next != head)
	{
		temp = temp->next;
		cout<<" + "temp->constant<<" X^ "<<temp->exponent;
	}
}

//Function to subtract the two polynomials and make a new linked list.
void node::add(node *h3, node *h1, node *h2)
{
	int min;

	node *one;
	node *two;
	one = h1 -> next;
	two = h2 -> next;

	while((one != h1) && (two != h2))
	{
		if(one->exponent == two->exponent)
		{
			min = one->constant + two->constant;
			insertNode(h3,min,one->exponent);
			one = one->next;
			two = two->next;
		}
		else if(one->exponent > two->exponent)
		{
			insertNode(h3,one->constant,one->exponent);
			one = one->next;
		}
		else
		{
			insertNode(h3,two->constant,two->exponent);
			two = two->next;
		}
	}

	while(one != h1)
	{
		insertNode(h3,one->constant,one->exponent);
		one = one -> next;
	}

	while(two !=h2)
	{
		insertNode(h3,two->constant,two->exponent);
		two = two -> next;
	}
}

//Main function.
void main()
{
	clrscr();
	node obj;
	int c,e,num;
	node *head1, *head2, *head3;
	head1 = new node;
	head2 = new node;
	head3 = new node;
	head1 -> next = head1;
	head2 -> next = head2;
	head3 -> next = head3;
	cout<<"\nEnter the number of elements in first polynomial\n";
	cin>>num;
	while(num>0)
    {
	cout<<"\nEnter the exponent\n";
	cin>>e;
	cout<<"\nEnter the constant for the exponent\n";
	cin>>c;
	obj.insertNode(head1,c,e);
	num--;
    }

    cout<<"\nEnter the number of elements in the polynomial to be added\n";
	cin>>num;
	while(num>0)
    {
	cout<<"\nEnter the exponent\n";
	cin>>e;
	cout<<"\nEnter the constant for the exponent\n";
	cin>>c;
	obj.insertNode(head2,c,e);
	num--;
    }
    cout<<"\nPolynomial 1 is : \n\n";
    obj.display(head1);
    cout<<"\nPolynomial 2 is : \n\n";
    obj.display(head2);
    obj.add(head3,head1,head2);

	cout<<"\n\nResult of addition of the two polynomials :\n\n";

	obj.display(head3);
	getch();
}