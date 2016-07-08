#include <iostream>

using namespace std;

class node
{
private:
	int data;
	node* next;
public:
	node()
	{
		next = NULL;
	}
	node* insert(node*,int);	
	void display(node*);
	node* unionList(node*,node*);
	node* intersection(node*,node*);
};

node* node::insert(node* head,int item)
{
	node* temp = new node();
	temp->data = item;
	temp->next=NULL;
	node* h=head;
	if(head == NULL)
	{
		h = head = temp;
		return h;
	}
	else
	{
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next = temp;
		return h;
	}
}

void node::display(node* root)
{
	if(root == NULL)
		cout<<"Empty List!\n";
	else
	{
		while(root!=NULL)
		{
			cout<<root->data<<"\t";
			root=root->next;
		}
		cout<<endl;
	}
}

node* node::unionList(node* root1,node* root2)
{
	if(root1==NULL && root2==NULL)
		return NULL;
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	node* temp;
	node* root3 = NULL;
	node* head3;
	node* r1 = root1;
	node* r2 = root2;
	while(root1!=NULL)
	{
		temp = new node();
		temp->data = root1->data;
		temp->next = NULL;
		if(root3 == NULL)
		{
			head3 = root3 = temp;
		}
		else
		{
			root3->next = temp;
			root3 = root3->next;
		}
		root1=root1->next;
	}
	root1 = r1;
	int flag = 1;
	while(root2!=NULL)
	{
		while(root1!=NULL)
		{
			if(root2->data == root1->data)
			{
				flag = 0;
			}	
			root1=root1->next;		
		}
		if(flag==1)
		{
			temp = new node();
			temp->data = root2->data;
			temp->next = NULL;
			if(root3==NULL)
			{
				head3 = root3 = temp;
			}
			else
			{
				root3->next = temp;
				root3=root3->next;
			}
		}
		flag=1;
		root1 = r1;
		root2=root2->next;
	}
	return head3;
}

node* node::intersection(node* root1,node* root2)
{
	node* r1 = root1;
	node* r2 = root2;
	if(r1==NULL && r2==NULL)
		return NULL;
	if(r1==NULL)
		return NULL;
	if(r2==NULL)
		return NULL;
	node* temp;
	node* root3=NULL;
	node* head3;
	while(r1!=NULL)
	{
		while(r2!=NULL)
		{
			if(r1->data==r2->data)
			{
				temp = new node();
				temp->data = r1->data;
				temp->next = NULL;
				if(root3==NULL)
				{
					head3=root3=temp;
				}
				else
				{
					root3->next=temp;
					root3=root3->next;
				}
			}
			r2=r2->next;
		}
		r2 = root2;
		r1=r1->next;
	}
	return head3;
}


int main(int argc, char const *argv[])
{
	node n1;
	node* head1 = NULL;
	cout<<"Enter the number of elements you want to enter in the first list\n";
	int n;
	cin>>n;
	int ele;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter an element\n";
		cin>>ele;
		head1 = n1.insert(head1,ele);
	}
	cout<<"First list:\n";
	n1.display(head1);
	cout<<"Enter the number of elements you want to enter in the second list\n";
	cin>>n;
	node* head2 = NULL;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter an element\n";
		cin>>ele;
		head2 = n1.insert(head2,ele);
	}
	cout<<"Second list:\n";
	n1.display(head2);
	cout<<"Union of the two list:\n";
	node* headUnion = n1.unionList(head1,head2);
	n1.display(headUnion);
	cout<<"Intersection of the two list:\n";
	node* headIntersection = n1.intersection(head1,head2);
	n1.display(headIntersection);
	return 0;
}