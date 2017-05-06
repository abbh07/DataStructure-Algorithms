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
	    void insert();
	    void disp();
	    void in_before();
	    void in_after();
	    void del();
	    void traverse();
	    void rev();
	  };
void main()
{node obj;
 int ch,n;
 clrscr();
 cout<<"enter no. of elements:-"<<endl;
 cin>>n;
 for(int i=0 ; i<n ; i++)
    obj.insert();
 obj.disp();
 cout<<endl;
 while(1)
 {cout<<"1.Insert before \n 2.Insert after \n 3.Delete \n 4.Traverse"<<endl;
  cout<<"5.Reverse \n6.Exit \n";
  cout<<"enter your choice"<<endl;
  cin>>ch;
  switch(ch)
  {case 1 : obj.in_before();obj.disp();break;
   case 2 : obj.in_after();obj.disp();break;
   case 3 : obj.del();obj.disp();break;
   case 4 : obj.traverse();break;
   case 5 : obj.rev();obj.disp();break;
   case 6 : exit(0);
   default : cout<<"enter correctly!"<<endl;
  }
  getch();
 }
}
void node::insert()
{node *temp = new node;
 temp->next = NULL;
 cout<<"enter value"<<endl;
 cin>>temp->data;
 if(head!=NULL && tail!=NULL)
 {tail->next=temp;
  temp->prev=tail;
  tail=temp;
 }
 else
   tail=head=temp;
}
void node::disp()
{node *temp=head;
 if(temp==NULL)
   cout<<"empty!"<<endl;
 while(temp!=NULL)
 {cout<<temp->data<<"\t";
  temp=temp->next;
 }
 cout<<endl;
}
void node::rev()
{node *temp=head, *r;
 head=NULL;
 while(temp!=NULL)
 {
  r=temp->next;
  temp->prev=temp->next;
  temp->next=head;
  head=temp;
  temp=r;
 }
}
void node::traverse()
{ node *temp=head;
  if(temp==NULL)
  { cout<<"list empty!"<<endl;
    return;
  }
  cout<<"contents :-"<<endl;
  while(temp!=NULL)
  { cout<<temp->data<<endl;
    temp=temp->next;
  }
}
void node::del()
{ cout<<"enter element to be deleted"<<endl;
  int item;
  cin>>item;
  node *temp=head, *d;
  d->next=NULL;
  if(head->data==item)
  {head=head->next;
   delete (temp);
  }
  else
  { while(temp!=NULL)
    { if(temp->data==item)
      { d->next=temp->next;
        temp->next->prev=d;
        delete(temp);
      }
      d=temp;
      temp=temp->next;
    }
  }
}
void node::in_after()
{cout<<"enter element :-"<<endl;
 int a,pos=0,c=1;
 cin>>a;
 int count=1;
 node *temp=head;
 while(temp!=NULL)
 { if(temp->data == a)
   { pos = c-1;
     break;
   }
   temp=temp->next;
   c++;
 }
 if(pos==0)
 { cout<<"element not present!"<<endl;
   return;
 }
 while(count<pos-1)
 {temp=temp->next;
  count++;
 }
 node *link=new node;
 cout<<"enter value"<<endl;
 cin>>link->data;
 link->next=temp->next;
 temp->next->prev=link;
 temp->next=link;
 link->prev=temp;
}
void node::in_before()
{cout<<"element:-"<<endl;
 int a,pos=0,c=1;
 cin>>a;
 node *temp=head;
 node *link=new node;
 link->next=NULL;
 while(temp!=NULL)
 { if(temp->data == a)
   { pos = c;
     break;
   }
   temp=temp->next;
   c++;
 }
 if(pos==0)
 { cout<<"element not present!"<<endl;
   return;
 }
 temp=head;
 cout<<"enter value"<<endl;
 cin>>link->data;
 if(pos==1)
 {head->prev=link;
  head=link;
  link->next=temp;
 }
 else
 {int count=1;
  while(count<pos-1)
  {temp=temp->next;
   count++;
  }
  link->next=temp->next;
  temp->next->prev=link;
  temp->next=link;
  link->prev=temp;
 }
}