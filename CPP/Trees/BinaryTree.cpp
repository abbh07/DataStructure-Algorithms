#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct node
{
	node* left;
	node* right;
	int data;
};


node* insert_bst(node* root, int item)
{
	node* n = new node;
	n->data = item;
	n->left = n->right = NULL;
	if(root == NULL)
	{
		root = n;
		return root;
	}
	node* parent = NULL;
	node* current = root;
	while(current != NULL)
	{
		parent = current;
		if(item < current->data)
		{
			current = current->left;
		}
		else if(item > current->data)
		{
			current = current->right;
		}
	}
	if(item < parent->data)
	{
		parent->left = n;
	}
	else
	{
		parent->right = n;
	}
	return root;
}

void levelorder(node* root)
{
	if(root == NULL)
		return;
	queue <node*> q;
	q.push(root);
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left != NULL)
			q.push(root->left);
		if(root->right != NULL)
			q.push(root->right);
	}

}

void reverse_levelorder(node* root)
{
	if(root == NULL)
		return;
	queue<node*> q;
	stack<node*> s;
	q.push(root);
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		s.push(root);
		if(root->right != NULL)
			q.push(root->right);
		if(root->left != NULL)
			q.push(root->left);
	}
	while(!s.empty())
	{
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
	}
}

void spiral_levelorder(node* root)
{
	if(root == NULL)
		return;
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			root = s1.top();
			s1.pop();
			cout<<root->data<<" ";
			if(root->left != NULL)
				s2.push(root->left);
			if(root->right != NULL)
				s2.push(root->right);
		}
		while(!s2.empty())
		{
			root = s2.top();
			s2.pop();
			cout<<root->data<<" ";
			if(root->right != NULL)
				s1.push(root->right);
			if(root->left != NULL)
				s1.push(root->left);
		}
	}
}

void preorder(node* root)
{
	if(root==NULL)
		return;
	stack<node*> s;
	s.push(root);
	while(!s.empty())
	{
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		if(root->right != NULL)
			s.push(root->right);
		if(root->left != NULL)
			s.push(root->left);
	}
}

void postorder(node* root)
{
	if(root == NULL)
		return;
	stack<node*> s1,s2;
	s1.push(root);
	while(!s1.empty())
	{
		root = s1.top();
		s1.pop();
		s2.push(root);
		if(root->left != NULL)
			s1.push(root->left);
		if(root->right != NULL)
			s1.push(root->right);
	}
	while(!s2.empty())
	{
		root = s2.top();
		s2.pop();
		cout<<root->data<<" ";
	}
}

void inorder(node* root)
{
	if(root == NULL)
		return;
	stack<node*> s;
	while(true)
	{
		if(root != NULL)
		{
			s.push(root);
			root = root->left;			
		}
		else
		{
			if(!s.empty())
			{
				root = s.top();
				s.pop();
				cout<<root->data<<" ";
				root = root->right;
			}
			else
				break;
		}
	}
}

void morris_inorder(node* root)
{
	node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{
			node* predecessor = current->left;
			while(predecessor->right != NULL && predecessor->right != current)
			{
				predecessor = predecessor->right;
			}
			if(predecessor->right == NULL)
			{
				predecessor->right = current;
				current = current->left;
			}
			else
			{
				predecessor->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
}

void morris_preorder(node* root)
{
	node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{
			node* predecessor = current->left;
			while(predecessor->right != NULL && predecessor->right != current)
			{
				predecessor = predecessor->right;
			}
			if(predecessor->right == NULL)
			{
				predecessor->right = current;
				cout<<current->data<<" ";
				current = current->left;
			}
			else
			{
				predecessor->right = NULL;
				current = current->right;
			}
		}
	}
}


//Assuming the keys exist in the tree
node* lca_bst(node* root, int data1, int data2)
{
	if(root == NULL)
		return NULL;
	while(root != NULL)
	{
		if(data1 < root->data && data2 < root->data)
		{
			root=root->left;
		}
		else if(data1 > root->data && data2 > root->data)
		{
			root=root->right;
		}
		else
		{
			break;
		}
	}
	return root;
}

//Assuming the keys exist in the tree
node* lca_bt(node* root, int d1, int d2)
{
	if(root == NULL)
		return NULL;
	if(root->data == d1 || root->data == d2)
		return root;
	node* left = lca_bt(root->left,d1,d2);
	node* right = lca_bt(root->right,d1,d2);
	if(left != NULL && right != NULL)
		return root;
	if(left == NULL && right == NULL)
		return NULL;
	return left!=NULL ? left:right;
}

bool isBst(node* root, int minrange, int maxrange)
{
	if(root == NULL)
		return true;
	if(root->data > minrange && root->data < maxrange && isBst(root->left,minrange,root->data) && isBst(root->right,root->data,maxrange))
		return true;
	else 
		return false;
}

bool isSame(node* r1, node* r2)
{
	if(r1==NULL && r2==NULL)
		return true;
	if(r1==NULL || r2==NULL)
		return false;

	if(r1->data == r2->data && isSame(r1->left,r2->left) && isSame(r1->right,r2->right))
		return true;
	else
		return false;
}

int tree_size(node* root)
{
	if(root == NULL)
		return 0;
	int left_tree_size = tree_size(root->left);
	int right_tree_size = tree_size(root->right);
	return left_tree_size + right_tree_size + 1;
}

int largest_bst(node* root)
{
	if(isBst(root,INT_MIN,INT_MAX))
		return tree_size(root);
	else
		return max(largest_bst(root->left),largest_bst(root->right));
}

int tree_height(node* root)
{
	if(root == NULL)
		return -1;
	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);
	return max(left_height,right_height) + 1;
}

bool root_to_leaf_sum(node* root, int sum)
{
	if(root == NULL)
		return false;
	if(root->left == NULL && root->right == NULL && root->data == sum)
		return true;
	else
		return root_to_leaf_sum(root->left,sum-root->data) || root_to_leaf_sum(root->right,sum-root->data);
}

node* mirror(node* root)
{
	if(root == NULL)
		return NULL;
	node* left = root->left;
	root->left = mirror(root->right);
	root->right = mirror(left);
	return root;
}

void doubleTree(node* root)
{
	if(root == NULL)
		return;
	doubleTree(root->left);
	node* n = new node;
	n->left = n->right = NULL;
	n->data = root->data;
	n->left = root->left;
	root->left = n;
	doubleTree(root->right);
}

void printPaths(node* root, int path[], int len)
{
	if(root == NULL)
		return;
	path[len++] = root->data;

	if(root->left == NULL && root->right == NULL)
	{
		for(int i=0;i<len;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}

	printPaths(root->left,path,len);
	printPaths(root->right,path,len);
}

//summation of T(i-1)T(n-i) for all i>=1 and i<=n
int countTrees(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		sum += countTrees(i-1)*countTrees(n-i);
	}
	return sum;
}

int main()
{
	int n;
	cout<<"Enter number of nodes\n";
	cin>>n;
	node* root = NULL;
	int val;
	for(int i=0;i<n;i++)
	{
		cin>>val;
	 	root = insert_bst(root,val);
	}

	cout<<"Inorder:"<<endl;
	inorder(root);
	cout<<endl;

	cout<<"Morris Inorder:"<<endl;
	morris_inorder(root);
	cout<<endl;

	cout<<"Levelorder:"<<endl;
	levelorder(root);
	cout<<endl;

	cout<<"Reverse Levelorder:"<<endl;
	reverse_levelorder(root);
	cout<<endl;

	cout<<"Spiral Levelorder:"<<endl;
	spiral_levelorder(root);
	cout<<endl;

	cout<<"Preorder:"<<endl;
	preorder(root);
	cout<<endl;

	cout<<"Morris Preorder:"<<endl;
	morris_preorder(root);
	cout<<endl;

	cout<<"Postorder"<<endl;
	postorder(root);
	cout<<endl;

	int path[100];
	cout<<"All root to leaf paths:"<<endl;
	printPaths(root,path,0);

	cout<<"Tree Size: "<<tree_size(root)<<endl;
	cout<<"Tree Height: "<<tree_height(root)<<endl;
	cout<<"Is BST: "<<isBst(root,INT_MIN,INT_MAX)<<endl;

	// cout<<"Enter two keys:"<<endl;
	// int d1,d2;
	// cin>>d1>>d2;
	// cout<<"Lowest Common Ancestor: "<<lca_bst(root,d1,d2)->data<<endl;
	// cout<<"Lowest Common Ancestor: "<<lca_bt(root,d1,d2)->data<<endl;

	cout<<"Largest BST: "<<largest_bst(root)<<endl;

	doubleTree(root);
	cout<<"Inorder traversal of the double tree:"<<endl;
	inorder(root);
	cout<<endl;

	root = mirror(root);
	cout<<"Inorder of mirror:"<<endl;
	inorder(root);
	cout<<endl;

	//int num;
	//cout<<"Enter number of nodes:"<<endl;
	//cin>>num;
	//cout<<"Total possibilities: "<<countTrees(num)<<endl;
	// int sum;
	// cout<<"Enter sum"<<endl;
	// cin>>sum;
	// cout<<"Root to leaf sum exists: "<<root_to_leaf_sum(root,sum)<<endl;

	// node* root2 = NULL;
	// cout<<"Enter number of nodes\n";
	// cin>>n;
	// while(n--)
	// {
	// 	cin>>val;
	// 	root2 = insert_bst(root2,val);
	// }

	// cout<<"Is Same: "<<isSame(root,root2)<<endl;
	return 0;
}