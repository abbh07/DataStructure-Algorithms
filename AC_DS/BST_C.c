#include<stdio.h>
#include<stdlib.h>

//Structure of a node
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node* NODE;

//Function to add a node to tree
NODE createNode(NODE root, int item)
{
    if(root == NULL)
    {
        NODE temp;
        temp = (NODE)malloc(sizeof(struct node));
        temp -> info = item;
        temp -> left = NULL;
        temp -> right = NULL;
        root = temp;
    }
    else if((item) < (root->info))
       root->left = createNode((root->left), item);
    else if((item)> (root->info))
        root -> right = createNode((root->right), item);
    else
        printf("\nERROR : Duplicate item!\n");
        return root;
}

//Inorder display function
void inorder(NODE root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d ",(root->info));
        inorder(root->right);
    }
}

/*
//Postorder display function
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->info);
    }
}

//Preorder display function
void preorder(NODE root)
{
    printf(" %d ",root->info);
    preorder(root->left);
    preorder(root->right);
}
*/
//Main Function
void main()
{
	//clrscr();
    int choice, item;
    NODE root = NULL;
    while(1)
    {
        printf("\n1.Add Element\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter element to be added\n");
            scanf("%d",&item);
            root=createNode(root, item);
            break;
        case 2:
            printf("\nINORDER DISPLAY\n");
            inorder(root);
            //printf("\nPREORDER DISPLAY\n");
            //preorder(root);
            //printf("\nPOSTORDER DISPLAY\n");
            //postorder(root);
            break;
        case 3:
            exit(0);
        }
	}
}
