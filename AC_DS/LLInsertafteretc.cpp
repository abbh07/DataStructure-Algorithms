#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class node{ int data;
	    node *next, *prev;
	    node *head, *tail;
	    int count;
	   public:
	    node()
	    {head = NULL;
	     tail = NULL;
	     count=0;
	    }
	    void insert();
	    void disp();
	    void in_after();
	    void del();
	    void traverse();
	  };
int main()
{
    node obj;
 int ch,n;
//clrscr();
 cout<<"enter no. of elements:-"<<endl;
 cin>>n;
 for(int i=0 ; i<n ; i++)
    obj.insert();
 obj.disp();
 cout<<endl;
 while(1)
 {cout<<"1.Insert after\n2.Delete";
  cout<<"\n3.Exit \n";
  cout<<"enter your choice"<<endl;
  cin>>ch;
  switch(ch)
  {
   case 1 : obj.in_after();obj.disp();break;
   case 2 : obj.del();obj.disp();break;
   case 3 : exit(0);
   default : cout<<"enter correctly!"<<endl;
  }
  //getch();
  //return 0;
 }
 return 0;
}
void node::insert()
{node *temp = new node;
 temp->next = NULL;
 cout<<"enter value"<<endl;
 cin>>temp->data;
 if(head!=NULL && tail!=NULL)
 {tail->next=temp;
  temp->prev=tail;
  temp->next=head;
  head->prev=temp;
  tail=temp;
  count++;
 }
 else
 {
   tail=head=temp;
   head->next=head;
   head->prev=head;
   count++;
   }
  // cout<<tail->next->data<<"\n";
}
void node::disp()
{
    node *temp=head;
 if(count==0)
 {
   cout<<"empty!"<<endl;
   return;
 }
   cout<<temp->data<<"\t";
   temp=temp->next;
 while(temp!=head)
 {cout<<temp->data<<"\t";
  temp=temp->next;
 }
 cout<<endl;
}
void node::del()
{ cout<<"enter element to be deleted"<<endl;
  int item;
  cin>>item;
  node *temp=head;
  node *d=head;
  if(head->data==item)
  {
  head=head->next;
  tail->next=head;
  head->prev=tail;
   delete (temp);
   count--;
  }
  else
  {
  temp=temp->next;
  if(tail->data==item)
  {
  temp=tail;
  tail=tail->prev;
  tail->next=head;
  head->prev=tail;
  delete(temp);
  count--;
  return;
  }
   while(temp!=head)
    { if(temp->data==item)
      {
          cout<<temp->data<<"\n";
          cout<<head->data<<"\n";
          cout<<tail->data<<"\n";
          d->next=temp->next;
	temp->next->prev=d;
	delete(temp);
	count--;
	break;
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
 if(head->data==a)
 {
 node *link=new node;
 cout<<"enter value"<<endl;
 cin>>link->data;
 link->next=head->next;
 head->next->prev=link;
 head->next=link;
 link->prev=head;
 count++;
 return;
 }
 int co=1;
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
 while(co<pos-1)
 {temp=temp->next;
  co++;
 }
 node *link=new node;
 cout<<"enter value"<<endl;
 cin>>link->data;
 if(link->data==tail->data)
 {
    tail->next=link;
    link->prev=tail;
    tail=link;
    tail->next=head;
    head->prev=tail;
    count++;
 }
 else
 {
 link->next=temp->next;
 temp->next->prev=link;
 temp->next=link;
 link->prev=temp;
 count++;
 }
}

