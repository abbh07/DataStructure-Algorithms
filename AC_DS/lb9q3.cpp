#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
//using namespace std;
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
    int tree_compare (node*,node*);
    void display(node*,int);
    node* copyy(node*);
    int compare(node*,node*);
    void swapp(node*);
};
void node:: swapp(node *root)
{
    if(root==NULL)
        return;
    if(root->right ==NULL && root->left ==NULL)
        return;
    else
    {
        node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        swapp(root->left);
        swapp(root->right);
    }
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
void main()
{
    clrscr;
    node obj;
    int choice, item,ele,elem;
    node* root = NULL;
    char cha[20];
    int len;
    while(1)
    {
        cout<<"\n1.Add Element\n2.Display\n3.Equal\n4.Mirror\n5.Copy\n6.Exit\n";
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
            {node* r1 = NULL;
            cout<<"Enter the contents of the second tree\n";
            cout<<"Enter no. of elements to be added.\n";
            cin>>len;int i=0;
            while(i<len){
            cout<<"\nEnter element to be added\n";
            cin>>item;
            r1=obj.insert(r1,item);i++;}
            int e=obj.tree_compare(root,r1);
            //int e=0;
            if(e==1)
                cout<<"Trees are equal";
            else
                cout<<"Trees are not equal";
                break;
            }
        case 4:

            {node* r2 = new node;
            r2=NULL;
                cout<<"Enter the contents of the second tree\n";
            cout<<"Enter no. of elements to be added.\n";
            cin>>len;int i=0;
            while(i<len){
            cout<<"\nEnter element to be added\n";
            cin>>item;
            r2=obj.insert(r2,item);
            i++;
            }
            obj.swapp(r2);
            int m=obj.compare(root,r2);
            if(m==1)
                cout<<"Mirror image";
            else
                cout<<"Trees are not the mirror image of each other";
                break;
            }
        case 5:
            {node* r3 = new node;
            r3=obj.copyy(root);
            cout<<"Copied tree is\n";
            obj.display(r3,0);
            break;
            }
        case 6:
            exit(0);
        default:
            cout<<"Please enter a valid choice";

	}
	
}
getch();
//return 0;
}
