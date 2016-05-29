#include <iostream>
using namespace std;

class node
{

private:
	int data;
	node* next;
	node* head;
public:
	node()
	{
		head=NULL;
	}
	
	node* getHead()
	{
		return head; 
	}

	void insertEnd(int item)
	{
		node* temp = new node();
		temp->data=item;
		temp->next=NULL;
		node* temp2 = head;
		if(head==NULL)
			head=temp;
		else
		{				
			while(temp2->next!=NULL)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
		}

	}

	void insertFront(int item)
	{
		node* temp=new node();
		temp->data=item;
		if(head!=NULL)
			temp->next=head;
		head=temp;
	}

	void insertPos(int item,int pos)
	{
		node* temp = new node();
		temp->data=item;
		int count=1;
		node* temp2 = head;
		while(temp2!=NULL)
		{
			temp2=temp2->next;
			count++;
		}
		if(pos>count)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		count=1;
		temp2 = head;
		if(head==NULL)
			head=temp;
		else
		{
			while(count<pos-1)
			{
				temp2=temp2->next;
				count++;
			}
			temp->next = temp2->next;
			temp2->next = temp;
		}
		
	}

	void deleteNode(int pos)
	{
		int count = 1;
		node* temp = head;
		if(head==NULL)
		{
			cout<<"Empty List"<<endl;
			return;
		}
		while(temp->next!=NULL)
		{
			temp=temp->next;
			count++;
		}
		if(pos>count)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		count=1;
		temp=head;
		if(pos == 1)
		{
			head=temp->next;
			delete(temp);
			return;
		}
		while(count<pos-1)
		{
			temp=temp->next;
			count++;
		}
		temp->next=temp->next->next;
	}

	void reverseList()
	{
		node *prev=NULL,*current=head,*next;
		while(current!=NULL)
		{
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
		}
		head=prev;
	}

	void reverseRecursion(node *temp)
	{
		//temp = head;
		if(temp->next == NULL)
		{
			head = temp;
			return;
		}
		reverseRecursion(temp->next);
		node *temp2 = temp->next;
		temp2->next = temp;
		temp->next = NULL;
	}

	void displayRecursion(node *temp)
	{
		//temp = head;
		if(temp == NULL)
		{
			return;
		}
		cout<<temp->data<<"\t";
		displayRecursion(temp->next);
	}

	void displayReverseRecursion(node *temp)
	{
		//temp = head;
		if(temp == NULL)
		{
			return;
		}
		displayReverseRecursion(temp->next);
		cout<<temp->data<<"\t";
	}

	void display()
	{
		node* temp = head;
		if(head==NULL)
			cout<<"Empty List!"<<endl;
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<endl;
		}		
	}	

	void sortList(node* root)//Bubble sort
	{
		int flag;
		node* ptr = NULL;
		node* ptr1 = root;
		do
		{
			flag=0;
			ptr1 = root;
			while(ptr1->next!=ptr)
			{
				if(ptr1->data>ptr1->next->data)
				{
					int temp = ptr1->data;
					ptr1->data = ptr1->next->data;
					ptr1->next->data = temp;
					flag=1;
				}
				ptr1 = ptr1->next;
			}
			ptr = ptr1;
		}while(flag);
	}			
	
};

int main()
{
	node n1;
	
	cout<<"Enter the number of items you want to insert"<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the data"<<endl;
		int d;
		cin>>d;
		n1.insertEnd(d);
	}
	node *temp = n1.getHead();
	cout<<"The elements of the linked list are"<<endl;
	n1.display();
	//n1.displayRecursion(temp);
	//cout<<endl;
	//n1.displayReverseRecursion(temp);
	//cout<<endl;
	//n1.insertPos(7,4);
	//n1.deleteNode(4);
	//n1.reverseList();
	//n1.reverseRecursion(temp);
	//n1.display();
	cout<<"List after bubble sorting:\n";
	n1.sortList(temp);
	n1.display();
	
	return 0;
}