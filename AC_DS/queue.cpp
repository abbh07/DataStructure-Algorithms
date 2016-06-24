#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;

//Structure of a node

class node
{
    public:
    int data;
    node *left;
    node *right;
    node* q[20];
    int front,rear;
    node(){
    left=NULL;
    right=NULL;
    rear=-1;
    front=0;
    }
    node* createNode(node*,int);
    void insert(node*);
    node* del();
    void levelorder(node*);
    void deletes(node*,int);
    void search(node*,int);
    void display(node*,int);

};
void node::search(node* r,int re)
{
    if(r==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    node* cur=r;
    while(cur!=NULL)
    {
        if(cur->data==re)
        {
            cout<<"Element found";
            return;
        }
        else if(cur->data>re)
            cur=cur->left;
        else
            cur=cur->right;
    }
    cout<<"Element not found";
}
void node::insert(node* a)
{
   q[++rear] = a;
}
node* node::del()
{
  return q[front++];
}
void node::levelorder(node* r)
{
  if(r==NULL)
    return;
  insert(r);
  while(1)
  {
    node *temp = del();
    if( !temp ) break;
    cout<< temp->data <<"\t";
    if(temp->left!=NULL)
      insert(temp->left);
    if(temp->right!=NULL)
      insert(temp->right);
  }
}

void node::display(node* r,int l)
{
    int i;
    if(r==NULL)
        return;
    display(r->right,l+1);
    for(i=0;i<l;i++)
        cout<<"\t";
    cout<<r->data<<endl;
    display(r->left,l+1);
}
void node::deletes(node*root,int ele)
{
    node* par,*cur,*suc;
    if(root==NULL)
        return;
    par=cur=NULL;
    node *qi=root;
    while(qi!=NULL)
    {
        if(qi->data==ele)
        {
            cur=qi;
            break;
        }
        par=qi;
        if(qi->data>ele)
            qi=qi->left;
        else
            qi=qi->right;

    }
    if(cur->left!=NULL&&cur->right!=NULL)
    {
        par=cur;
        suc=cur->right;
        while(suc->left!=NULL)
        {
            par=suc;
            suc=suc->left;
        }
        cur->data=suc->data;
        cur=suc;
    }
    if(cur->left==NULL&&cur->right==NULL)
    {
        if(par->right==cur)
            par->right=NULL;
        else
            par->left=NULL;
            delete(cur);
            return;
    }
    if(cur->left!=NULL&&cur->right==NULL)
    {
        if(par->left==cur)
        par->left=cur->left;
        else
            par->right=cur->left;
        delete(cur);
        return;

    }
     if(cur->left==NULL&&cur->right!=NULL)
    {
        if(par->left==cur)
        par->left=cur->right;
        else
            par->right=cur->right;
        delete(cur);
        return;

    }
}

//Function to add a node to tree
node* node::createNode(node*r,int item)
{
    if(r == NULL)
    {
        node* temp = new node;;
        temp -> data = item;
        temp -> left = NULL;
        temp -> right = NULL;
        r = temp;
    }
    else if((item) <= (r->data))
       r->left=createNode((r->left), item);
    else if((item)> (r->data))
       r->right=createNode((r->right), item);
       return r;
}
int main()
{
	//clrscr();
	node obj;
    int choice, item;
    node* root=NULL;
    while(1)
    {
        cout<<"\n1.Add Element\n2.Display\n3.Delete\n4.Search\n5.Level order\n6.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter element to be added\n";
            cin>>item;
            root=obj.createNode(root,item);
            break;
        case 2:
            cout<<"\nDisplay\n";
            obj.display(root,0);
            break;
        case 3:
            {
            int el=0;
            cout<<"Enter element to be deleted";
            cin>>el;
            obj.deletes(root,el);
            break;
            }
        case 4:
            {
            int e=0;
            cout<<"Enter element to be searched";
            cin>>e;
            obj.search(root,e);
            break;
            }
        case 5:
            {
            obj.levelorder(root);
            break;
            }
        case 6:
            exit(0);
        default:
            cout<<"Enter a valid choice";
        }

	}
	//getch();
	return 0;
}
