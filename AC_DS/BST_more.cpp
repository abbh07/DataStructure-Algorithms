#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//Structure of a node
class node
{
    public:
    int info;
    node *left;
    node *right;
    node()
    {
        left=right=NULL;
    }
    node* createNode(node*,int);
    void inorder(node*);
};int ar[20];int i=0;

//Function to add a node to tree
node* node::createNode(node* root, int item)
{
    if(root == NULL)
    {
        node* temp;
        temp = new node;
        temp -> info = item;
        temp -> left = NULL;
        temp -> right = NULL;
        root = temp;
    }
    else if((item) < (root->info))
       root->left = createNode((root->left), item);
    else
        root -> right = createNode((root->right), item);
        return root;
}

//Inorder display function
void node::inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        ar[i]=root->info;
        i++;
        inorder(root->right);
    }

}
//Main Function
int main()
{
	//clrscr();
    int choice, item;
    node obj;
    node* root = NULL;
    int flag=0;
    while(1)
    {
        cout<<"\n1.Add Element\n2.Display\n3.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter element to be added\n";
            cin>>item;
            root=obj.createNode(root, item);
            break;
        case 2:
            obj.inorder(root);
            for(int j=0;j<i-1;j++)
    {
        if(ar[i]>ar[i+1])
        {
            cout<<"Tree is not a BST";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"Tree is BST";
            //printf("\nPREORDER DISPLAY\n");
            //preorder(root);
            //printf("\nPOSTORDER DISPLAY\n");
            //postorder(root);
            break;
        case 3:
            exit(0);
        }
	}
	return 0;
}
