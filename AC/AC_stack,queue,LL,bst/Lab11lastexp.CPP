#include <iostream.h>
#include <cctype.h>
#include <conio.h>

//using namespace std;

class tree
{
private:
	char data;
	tree* left;
	tree* right;
public:
	tree* create(char []);
	double eval(tree*);
	void inorder(tree*);
	void preorder(tree*);
	void postorder(tree*);
};

tree* tree::create(char postfix[])
{
	tree* arr[50];
	int top=-1;
	int i=0;
	char c;
	while(postfix[i]!='\0')
	{
		c=postfix[i];
		tree* temp = new tree();
		temp->data = c;
		if(isalnum(c))
			arr[++top] = temp;
		else
		{
			temp->right = arr[top--];
			temp->left = arr[top--];
			arr[++top] = temp;
		}
		i++;
	}
	return arr[top]; //or return temp;
	// temp is the root of the newly created expression tree
}

double tree::eval(tree* root)
{
	switch(root->data)
	{
		case '+':return (eval(root->left)+eval(root->right));
					break;
		case '-':return (eval(root->left)-eval(root->right));
					break;
		case '*':return (eval(root->left)*eval(root->right));
					break;
		case '/':return (eval(root->left)/eval(root->right));
					break;
		default:if(isalpha(root->data))
				{
					cout<<"Enter the value for "<<(char)root->data<<endl;
					cin>>root->data;
					return root->data;
				}
	}
}

void tree::preorder(tree* root)
{
	if(root != NULL)
	{
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void tree::inorder(tree* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void tree::postorder(tree* root)
{
	if(root != NULL)
	{
		postorder(root->left);		
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}

void main()
{
	tree t1;
	tree *root = NULL;
	clrscr();
	cout<<"Enter the postfix expression"<<endl;
	char arr[50];
	cin>>arr;
	root = t1.create(arr);
	cout<<"Preorder traversal: "<<endl;
	t1.preorder(root);
	cout<<endl;
	cout<<"Inorder traversal: "<<endl;
	t1.inorder(root);
	cout<<endl;
	cout<<"Postorder traversal: "<<endl;
	t1.postorder(root);
	cout<<endl;
	cout<<"Evaluation of the string:\n";
	cout<<t1.eval(root)<<endl;
	getch();
	//return 0;
}