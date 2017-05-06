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

    node(){

    left=NULL;

    right=NULL;

    }

    node* createNode(node*,int);

    void inorder(node*);
    void removeLeaf(node*);

};

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

//Inorder display function

void node::inorder(node* root)

{

    if(root != NULL)

    {

        inorder(root->left);

        cout<<root->info<<"\t";

        inorder(root->right);

}

}
void node::removeLeaf(node* p){
if (p == NULL){
    return;
  }
  else{
    if (p->left || p->right){
      removeLeaf(p->left);
      removeLeaf(p->right);
    }
    else{
      delete p;
      return;
    }
  }
}

int main()

{

//clrscr();

node obj;

    int choice, item;

    node* root = NULL;

    while(1)

    {

        cout<<"\n1.Add Element\n2.Display\n3.Delete\n4.Exit";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"\nEnter element to be added\n";

            cin>>item;

            root=obj.createNode(root, item);

            break;

        case 2:

            cout<<"\nINORDER DISPLAY\n";

            obj.inorder(root);

            break;

        case 3:
            obj.removeLeaf(root);
            obj.inorder(root);
            break;

        case 4:


            exit(0);

        }

}
return 0;
//getch();

}
