#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;


class node
    {
        public:
        int exp;
        int cons;
        node* next;
        node* prev;
        node()
        {
            exp=0;
            cons=0;
            next=NULL;
            prev=NULL;
        }
        node* mul(node*,node*);
        node* add(node*,node*);
        node* check(node*);
        node* insert(node*,int,int);
        void display(node*);
    };
    node* node::check(node* h1)
    {
        node* t1 = h1;
        node* t2;
        while(t1->next!=h1)
            {
               t1=t1->next;
               t2 = h1;
               while(t2->next!=h1)
               {
                   t2=t2->next;
                   if((t1->exp==t2->exp)&&(t1!=t2))
                   {
                      t1->cons = t1->cons + t2->cons;
                      t2->prev->next = t2->next;
                      t2->next->prev = t2->prev;
                      delete(t2);
                   }
               }
            }
            return h1;
    }
    node* node::mul(node* h1,node* h2)
    {
        node* h3 = new node();
        h3->next = h3;
        h3->prev = h3;
        node* t1 = h1;
        node* t2 = h2;
        if(h1->next==h1)
            return h2;
        if(h2->next==h2)
            return h1;
        if(h1->next==h1 && h2->next==h2)
        {
            cout<<"Both the lists are empty\n";
            return NULL;
        }
        else{
            while(t1->next!=h1)
            {
               t1=t1->next;
               t2 = h2;
               while(t2->next!=h2)
               {
                    t2=t2->next;
                    int co = t1->cons * t2->cons;
                    int e = t1->exp + t2->exp;
                    h3 = insert(h3,co,e);
               }
            }
        }
        return h3;
    }
    node* node::add(node* h1,node* h2)
    {
        node* h3 = new node();
        h3->next = h3;
        h3->prev = h3;
        node* t1 = h1;
        node* t2 = h2;
        int fla = 0;
        if(h1->next==h1)
            return h2;
        if(h2->next==h2)
            return h1;
        if(h1->next==h1 && h2->next==h2)
        {
            cout<<"Both the lists are empty\n";
            return NULL;
        }

        else{
            while(t1->next!=h1)
            {
               t1=t1->next;
               t2 = h2;
               fla = 0;
               while(t2->next!=h2)
               {
                   t2=t2->next;
                   if(t1->exp==t2->exp)
                   {
                    fla = 1;
                    int co = t1->cons + t2->cons;
                    h3 = insert(h3,co,t1->exp);
                   }
               }
                        if(fla==0)
                        h3 = insert(h3,t1->cons,t1->exp);

            }
            int flag = 0;
            node* t = h3;
            node* m = h2;
                while(m->next!=h2)
                {
                    flag = 0;
                    m = m->next;
                    t = h3;
                    while(t->next!=h3)
                    {
                    t = t->next;
                    if(t->exp==m->exp)
                    {
                        flag = 1;
                        break;
                    }
                    }
                    if(flag==0)
                    h3 = insert(h3,m->cons,m->exp);
                }

                }
        return h3;
    }
    node* node::insert(node* h1,int c,int e)
    {
        node* temp = new node();
        temp->cons = c;
        temp->exp = e;

        if(h1->next==h1)
        {
            h1->next = temp;
            temp->prev = h1;
            temp->next = h1;
            h1->prev = temp;
        }
        else
        {
            node* t = h1;
            while(t->next!=h1)
                t=t->next;
            t->next=temp;
            temp->prev = t;
            temp->next = h1;
            h1->prev = temp;
        }
        return h1;
    }
    void node::display(node* h1)
    {
        if(h1->next==h1)
        {
            cout<<"\nList is empty\n";
            return;
        }
        node* t = h1->next;
        while(t!=h1)
        {
            cout<<"+ "<<"("<<t->cons<<") x^"<<"("<<t->exp<<") ";
            t = t->next;
        }
        cout<<"\n";

    }

int main()
{
    int choice = 0;
    node* h1 = new node();
    h1->next=h1;
    h1->prev=h1;
    node* h2 = new node();
    h2->next=h2;
    h2->prev=h2;
    node* h3;
    int n = 0;
    node ob;
    int i,c,e;

    while(1)
    {
        cout<<"\n1.Insert\n2.Add\n3.Multiply\n4.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:cout<<"Enter the number of elements in first list\n";
               cin>>n;
               for(i=0;i<n;i++)
               {
                   cout<<"Enter constant\n";
                   cin>>c;
                   cout<<"Enter exponent\n";
                   cin>>e;
                   h1 = ob.insert(h1,c,e);
               }

               cout<<"Enter the number of elements in second list\n";
               cin>>n;
               for(i=0;i<n;i++)
               {
                   cout<<"Enter constant\n";
                   cin>>c;
                   cout<<"Enter exponent\n";
                   cin>>e;
                   h2 = ob.insert(h2,c,e);
               }

                cout<<"Entered list are\n";
                cout<<"List 1\n";
                ob.display(h1);
                cout<<"\nList 2\n";
                ob.display(h2);

            break;
        case 2:h1 = ob.check(h1);
               h2 = ob.check(h2);
               ob.display(h1);
               ob.display(h2);
               h3 = ob.add(h1,h2);
               cout<<"Addition result\n";
               ob.display(h3);
            break;
        case 3:h3 = ob.mul(h1,h2);
               h3 = ob.check(h3);
               cout<<"Multiplication result\n";
               ob.display(h3);
            break;
        case 4:exit(0);
            break;
        default:cout<<"Enter a correct input\n";
        }
    }
    return 0;
}
