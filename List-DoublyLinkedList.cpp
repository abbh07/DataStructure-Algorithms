#include <iostream>

using namespace std;

class doubly
{
private:
	int data;
	doubly *llink;
	doubly *rlink;
	doubly *head;
public:
	doubly()
	{
		head = NULL;
	}

	void insertEnd (int);
	void display ();
};

void doubly::insertEnd (int item)
{
	doubly *temp = new doubly();
	temp->data = item;
	if(head == NULL)
	{
		head = temp;
		temp->rlink = NULL;
	}
	else
	{
		doubly *temp2 = head;
		while(temp2->rlink!=NULL)
		{
			temp2 = temp2->rlink;
		}
		temp2->rlink = temp;
		temp->llink = temp2;
		temp->rlink = NULL;
	}
}

void doubly::display()
{
	doubly *temp = head;
	if(temp == NULL)
	{
		cout<<"List Empty!"<<endl;
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->rlink;
	}
	cout<<endl;
}

int main()
{
	doubly d1;
	cout<<"How many elements you want to enter?"<<endl;
	int n;
	cin>>n;
	int num;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the element"<<endl;
		cin>>num;
		d1.insertEnd(num);
	}
	cout<<"The list is:"<<endl;
	d1.display();
	return 0;
}
