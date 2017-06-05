#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//Structure of a node
class node
{
    public:
    int info;
    node* s[20];
    node *left;
    node *right;
    node(){
    left=NULL;
    right=NULL;
    }
    node* insert(node*,int);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void push(node*);
    node* pop();
    node* parent(node*,int,node*);
    int anc(node*,int);
    int depth(node*);
    int leaf(node*);
    int tree_compare (node*,node*);

    void display(node*,int);
    node* copyy(node*);
    int compare(node*,node*);
};int top=-1;
void node::push(node *r)
{
    if(top == 19)
    {
        cout<<"\nOverflow\n";
        return;
    }
    s[++top]=r;
}
node* node::pop()
{
    if(top==-1)
        return NULL;
    node* r=s[top--];
    return r;
}
void node::inorder(node *root)
{
   while(1)
          {
             for(;root!=NULL;root=root->left)

                push(root);
            root=pop();
            if(root==NULL)
                break;
            cout<<root->info;
            root=root->right;
          }
}
void node::preorder(node* root)
{
    while(1)
          {
             for(;root;root=root->left)
             {
                cout<<root->info;
                push(root);
             }
            root=pop();
            if(!root)
                break;
            root=root->right;
          }
}
void node::postorder(node* root)
{
    while(1)
    {
        while(root)
        {
            push(root);
            root = root->left;
        }
        root = pop();
        if(!root)
            break;
        if(root->right != NULL)
        {
            push(root->right);
            push(root);
        }
        root = pop();
        if(root==NULL)
            break;
        if(root->right->info == pop()->info)
        {
            pop();
            push(root);
            root = root->right;
        }
        else
        {
            cout<<root->info;
            root = NULL;
        }
    }
}
node* node::parent(node* cur,int ele,node* prev)
{
    if(cur!=NULL)
    {
        parent(cur->left,ele,cur);
        if(ele==cur->info)
        {
            cout<<"\nParent:"<<prev->info;
            return prev;
        }
        parent(cur->right,ele,cur);
    }
    return NULL;
}
int node::anc(node* r,int t)
{
    if(r==NULL)
    return 0;
    if(r->info==t)
        return 1;
    if(anc(r->right,t)||anc(r->left,t))
    {
        cout<<r->info;
        return 1;
    }
    return 0;
}
int node::depth(node* r)
{
    if(r==NULL)
        return 0;
    else
        return max(depth(r->left),depth(r->right))+1;
}
int node::leaf(node* r)
{
    if(r==NULL)
        return 0;
    if(r->left==NULL&&r->right==NULL)
        return 1;
    else
        return leaf(r->right)+leaf(r->left);
}
  node* node::insert(node* root, int x)
{
	int i;
	node* pilot = root;
	node* temp=new node;;
	temp->info = x;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL)
		root = temp;
	else
	{
		char dir[10];
		cout<<"\nEnter the location to add node in terms of L and R\n";
		cin>>dir;
		int count=0;
		for(int j=0;dir[j]!='\0';j++)
            count++;
		for(i=0; i<count-1;i++)
		{
            if(dir[i] == 'l' || dir[i] == 'L')
            {
                if(pilot->left == NULL)
                {
                    cout<<"\nInvalid location\n";
                    return root;
                }
                else
                    pilot = pilot->left;
            }
            else if(dir[i] == 'r' || dir[i] == 'R')
            {
                if(pilot->right == NULL)
                {
                    cout<<"\nInvalid location\n";
                    return root;
                }
                else
                    pilot = pilot->right;
            }
            else
            {
                cout<<"\nInvalid input\n";
                return root;
            }

		}
		if(dir[i]=='l' || dir[i]== 'L')
		{
			if(pilot->left != NULL)
			{
				cout<<"\nLocation already occupied\n";
			}
			else
				pilot->left = temp;
		}
		else if(dir[i]=='r' || dir[i]=='R')
			if(pilot->right != NULL)
			{
				cout<<"\nLocation already occupied\n";
			}
			else
				pilot->right = temp;
	}
	return root;
}
int node::tree_compare (node* t1,node* t2)
{
  if (t1 == t2)  return 1;
  if ((t1 == NULL) || (t2 == NULL))  return 0;
  return ((t1->info == t2->info) && tree_compare (t1->left,  t2->left )
                                 && tree_compare (t1->right, t2->right));
}
void node::display(node* r,int l)
{
    int i;
    if(r==NULL)
        return;
    display(r->right,l+1);
    for(i=0;i<l;i++)
        cout<<"\t";
    cout<<r->info<<endl;
    display(r->left,l+1);
}
node* node::copyy(node *root) {
     node *new_root;
     if(root!=NULL){
         new_root=new node;
         new_root->info=root->info;
         new_root->left=copyy(root->left);
         new_root->right=copyy(root->right);
     } else return NULL;
     return new_root;
 }
int node::compare(node *list, node* list1)
{
    //int d;
    if (list == NULL && list1 == NULL)
    {
        return 1;
    }
    else if (list != NULL && list1 != NULL)
    {
        return(list->info == list1->info &&
        compare(list->left, list1->left) &&
        compare(list->right, list1->right));
    }
    else
    {
        return 0;
    }
}
int main()
{
    //clrscr;
	node obj;
    int choice, item,ele,elem;
    node* root = NULL;
    node* r1 = NULL;
    node* r2 = new node;
    node* r3 = new node;
    char cha[20];
    while(1)
    {
        cout<<"\n1.Add Element\n2.Display\n3.Inorder\n4.Preorder\n5.Postorder\n6.Parent\n7.Ancestor\n8.Depth\n9.Leaf\n10.Equal";
        cout<<"\n11.Mirror\n12.Copy\n13.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter element to be added\n";
            cin>>item;
            root=obj.insert(root,item);
            break;
        case 2:
            cout<<"\nDISPLAY\n";
            obj.display(root,0);
            break;
        case 3:
            cout<<"Inorder Display\n";
            obj.inorder(root);
            break;
        case 4:
            cout<<"Preorder Display\n";
            obj.preorder(root);
            break;
        case 5:
            cout<<"Postorder Display\n";
            obj.postorder(root);
            break;
        case 6:
            {
            cout<<"Enter element whose parent is to be checked\n";
            cin>>ele;
            node *a =obj.parent(root,ele,0);
            break;
            }
        case 7:
            {
            cout<<"Enter element whose ancestor is to be printed\n";
            cin>>elem;
            int q=obj.anc(root,elem);
            break;
            }
        case 8:
            {
            int b=obj.depth(root);
            cout<<"Depth of the tree is "<<b<<"\n";
            break;
            }
        case 9:
            {
            int c=obj.leaf(root);
            cout<<"Number  of leaf nodes in the tree are "<<c<<"\n";
            break;
            }
        case 10:
            {
            cout<<"Enter the contents of the second tree";
            cout<<"\nEnter element to be added\n";
            cin>>item;
            r1=obj.insert(r1,item);
            int e=obj.tree_compare(root,r1);
            //int e=0;
            if(e==1)
                cout<<"Trees are equal";
            else
                cout<<"Trees are not equal";
                break;
            }
        case 11:

            {cout<<"Enter the contents of the second tree";
            cout<<"\nEnter element to be added\n";
            cin>>item;
            r2=obj.insert(r2,item);
            int m=obj.compare(root,r1);
            if(m==1)
                cout<<"Mirror image";
            else
                cout<<"Trees are not the mirror image of each other";
                break;
            }
        case 12:
            {
            r3=obj.copyy(root);
            cout<<"Copied tree is\n";
            obj.display(r3,0);
            break;
            }
        case 13:
            exit(0);
        default:
            cout<<"Please enter a valid choice";

	}
    }
	//getch();
	return 0;
}
