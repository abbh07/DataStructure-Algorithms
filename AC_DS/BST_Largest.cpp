#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;

//Structure of a node
class node
{
    public:
    int info;
    node *left;
    node *right;
    node* s[20];
    node(){
    left=NULL;
    right=NULL;
    }
    node* createNode(node*,int);
    int largest(node*);
    void inorder(node*);
    void push(node*);
    node* pop();
};int top=-1;
//Function to add a node to tree
node* node::createNode(node* root, int item)
{
    if(root == NULL)
    {
        node* temp = new node;;
        temp -> info = item;
        temp -> left = NULL;
        temp -> right = NULL;
        root = temp;
    }
    else if((item) <= (root->info))
       root->left = createNode((root->left), item);
    else if((item)> (root->info))
        root -> right = createNode((root->right), item);
        return root;
}
void node::inorder(node *root)
{
    while(1)
          {
             for(;root!=NULL;root=root->left)
                push(root);
            root=pop();
            if(!root)
                break;
            cout<<root->info;
            root=root->right;
          }
}
void node::push(node *r)
{
    s[++top]=r;
}
node* node::pop()
{
    node* r=s[top--];
    return r;
}
   int node::largest( node* root )
{
    if ( root == NULL )
        return -1;
        if(root->right==NULL)
            return root->info;
    largest(root->right);

   /*
   For a general tree
    int left = largest(root->left);
    int right = largest ( root->right);
    if( root->info > left && root->info > right )
       return root->info;
    else
       return max ( left, right );*/
}
int main()
{
	//clrscr();
	node obj;
    int choice, item, a;
    node* root = NULL;
    while(1)
    {
        cout<<"\n1.Add Element\n2.Display Largest\n3.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter element to be added\n";
            cin>>item;
            root=obj.createNode(root, item);
            break;
        case 2:
            cout<<"\nLargest Number\n";
            obj.inorder(root);
            //cout<<a;
            break;
        case 3:
            exit(0);
        }

	}
	//getch();
	return 0;
}
