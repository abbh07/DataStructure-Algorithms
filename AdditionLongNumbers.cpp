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
			node* addList(node*,node*);
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

		node* node::addList(node* root1,node* root2)
		{
			if(root1 == NULL && root2 == NULL)
				return NULL;
			if(root1 == NULL)
				return root2;
			if(root2 == NULL)
				return root1;
			node* r1 = root1;
			node* r2 = root2;
			node* temp;
			int c=0;
			node* root3 = NULL;
			node* head3;
			while(r1!=NULL && r2!=NULL)
			{
				temp = new node();
				temp->next = NULL;
				int val = r1->data+r2->data+c;
				if(val<10)
				{
					temp->data = val;
					c=0;
				}
				else
				{
					temp->data = val%10;
					c=val/10;
				}
				if(root3 == NULL)
				{
					head3 = root3 = temp;
				}
				else
				{
					root3->next = temp;
					root3 = root3->next;
				}
				r1=r1->next;
				r2=r2->next;
			}
			while(r1!=NULL)
			{
				temp = new node();
				temp->data = r1->data;
				temp->next = NULL;
				root3->next = temp;
				root3 = root3->next;
				r1=r1->next;
			}
			while(r2!=NULL)
			{
				temp=new node();
				temp->data = r2->data;
				temp->next =NULL;
				root3->next = temp;
				root3 = root3->next;
				r2=r2->next;
			}
			return head3;
		}

		int main()
		{
			node n;
			cout<<"Enter the number of digits in the first number\n";
			int s;
			cin>>s;
			int num;
			node *head1 = NULL,*head2 = NULL;
			for(int i=0;i<s;i++)
			{
				cout<<"Enter the first number from lsb to msb\n";
				cin>>num;
				head1 = n.insert(head1,num);
			}
			cout<<"Enter the number of digits in the second number\n";
			cin>>s;
			for(int i=0;i<s;i++)
			{
				cout<<"Enter the second number from lsb to msb\n";
				cin>>num;
				head2 = n.insert(head2,num);
			}
			cout<<"First list:\n";
			n.display(head1);
			cout<<"Second list:\n";
			n.display(head2);
			cout<<"Addition of the two lists:\n";
			node *head3 = n.addList(head1,head2);
			n.display(head3);
			return 0;
		}