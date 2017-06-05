#include<iostream.h>
#include<conio.h>
#include<process.h>
class node{ int data;
	        node *next, *prev;
	        node *head, *tail;
	       public:
	        node()
	        {head = NULL;
	         tail = NULL;
	        }
	        node* insert(int);
	        void disp(node*);
            node* concat();
          };node *head1, *head2;
void main()
{node obj;
 node *t = new node;
 int n,m;
 clrscr();
 cout<<"enter no. of elements for 1st : ";cin>>n;
 cout<<"enter no. of elements for 2nd : ";cin>>m;
 head1=obj.insert(n);
 head2=obj.insert(m);
 t= obj.concat();
 obj.disp(t);
 getch();
}
node *node::insert(int a)
{head=NULL;
 tail=NULL;
 for(int i=0 ; i<a ; i++)
 {node *temp = new node;
  temp->next = NULL;
  cout<<"enter value"<<endl;
  cin>>temp->data;
  if(head!=NULL && tail!=NULL)
  { tail->next=temp;
    tail=temp;
  }
  else
    tail=head=temp;
 }
 return head;
}
void node::disp(node *t)
{if(t==NULL)
   cout<<"empty!"<<endl;
 while(t!=NULL)
 {cout<<t->data<<"\t";
  t=t->next;
 }
 cout<<endl;
}
node* node::concat()
{node *h = new node;
 if(head1==NULL && head2==NULL)
   return NULL;
 if(head1==NULL)
   return head2;
 if(head2==NULL)
   return head1;
 h=head1;
 while(h->next!=NULL)
 {h=h->next;}
  h->next=head2;
  head2->prev=h;
  return head1;
}