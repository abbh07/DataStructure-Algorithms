#include <iostream>

using namespace std;

class bstNode
{
private:
	int data;
	bstNode *left;
	bstNode *right;
	
public:
	bstNode* Insert (bstNode*,int);
	bool Search (bstNode*,int);
	void preorder (bstNode*);
	void inorder (bstNode*);
	void postorder (bstNode*);
	void levelorder (bstNode*);
	int countLeaves (bstNode*,int);
	bstNode* Copy (bstNode*);
	int findMin (bstNode*);
	int findMax (bstNode*);
	int max (int,int);
	int height (bstNode*);
	bstNode* insertNode (bstNode*,int);
	bstNode* deleteNode (bstNode*,int);
	int compare (bstNode* , bstNode*);
	bool printAncestors(bstNode*,int);
	bstNode* printParent(bstNode*,int,bstNode*);
	bool isMirror(bstNode*,bstNode*);
};

bstNode* bstNode::Insert (bstNode *root, int item)
{
	bstNode* newNode = new bstNode();
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root == NULL)
	{
		root = newNode;
	}
	else if(item <= root->data)
	{
		root->left = Insert(root->left,item);
	}
	else if(item > root->data)
	{
		root->right = Insert(root->right,item);
	}
	return root;
}

bool bstNode::Search(bstNode *root,int item)
{
	if(root == NULL)
		return false;
	if(item == root->data)
		return true;
	if(item <= root->data)
	{
		return Search(root->left,item);
	}
	if(item > root->data)
	{
		return Search(root->right,item);
	}
}

void bstNode::preorder(bstNode* root)
{
	if(root != NULL)
	{	
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void bstNode::inorder(bstNode *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

void bstNode::postorder(bstNode* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		cout<<root->data<<"\t";
		postorder(root->right);
	}

}

void bstNode::levelorder(bstNode* root)
{
	bstNode* arr[50] = {NULL};
	int front=0;
	int rear=0;
	while(root != NULL)
	{
		cout<<root->data<<"\t";
		if(root->left)
			arr[rear++] = root->left;
		if(root->right)
			arr[rear++] = root->right;
		root = arr[front++];
	}
}

int bstNode::countLeaves(bstNode* root,int count)
{
	if(root != NULL)
	{
		count = countLeaves(root->left,count);
		if((root->left == NULL) && (root->right == NULL))
			count++;
		count = countLeaves(root->right,count);
	}
	return count;
}

bstNode* bstNode::Copy (bstNode* root)
{
	bstNode *newRoot = new bstNode();
	if(root == NULL)
		return NULL;
	newRoot->data = root->data;
	newRoot->left = Copy(root->left);
	newRoot->right = Copy(root->right);
	return newRoot;
}

int bstNode::findMin (bstNode *root)
{
	if(root == NULL)
	{
		cout<<"Empty Tree!"<<endl;
		return -1;
	}
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int bstNode::findMax (bstNode *root)
{
	if(root == NULL)
	{
		cout<<"Empty Tree!"<<endl;
		return -1;
	}
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

int bstNode::max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int bstNode::height(bstNode* root)
{
	if(root == NULL)
		return -1;
	else
		return (max(height(root->left),height(root->right))+1);
}

bstNode* bstNode::insertNode (bstNode* root,int data)
{
	bstNode* newNode = new bstNode();
	newNode->data = data;
	if(root == NULL)
		return newNode;
	if(data < root->data)
		root->left = insertNode(root->left,data);
	else if(data > root->data)
		root->right = insertNode(root->right,data);
	return root;

}

bstNode* bstNode::deleteNode (bstNode* root,int data)
{
	if(root == NULL)
		return root;
	else if(data < root->data)
		root->left = deleteNode(root->left,data);
	else if(data >root->data)
		root->right = deleteNode(root->right,data);
	else
	{
		//Case 1: No child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}

		//Case 2: 1 child
		else if(root->left == NULL)
		{
			bstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			bstNode *temp = root;
			root = root->left;
			delete temp;
		}

		//Case 3: 2 children
		else
		{
			root->data = findMin(root->right);
			root->right = deleteNode(root->right,data);
		}
	}
	return root;
}

int bstNode::compare (bstNode* root1, bstNode* root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	else if(root1 == NULL || root2 == NULL)
		return 0;
	else if(root1->data == root2->data)
	{
		int p = compare(root1->left,root2->left);
		int q = compare(root1->right,root2->right);
		return p*q;
	}
	else
		return 0;
}

bool bstNode::printAncestors(bstNode* root,int key)
{
	if(root==NULL)
		return false;
	if(root->data==key)
		return true;
	if(printAncestors(root->left,key)||printAncestors(root->right,key))
	{
		cout<<root->data<<"\t";
		return true;
	}
	return false;
}

bstNode* bstNode::printParent(bstNode* cur,int key,bstNode* prev)
{
	if(cur==NULL)
		return NULL;
	printParent(cur->left,key,cur);
	if(key==cur->data)
	{
		cout<<prev->data<<endl;
		return prev;
	}
	
	printParent(cur->right,key,cur);
	return NULL;

}

bool bstNode::isMirror(bstNode* root1,bstNode* root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;
	return ((root1->data == root2->data) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left));
}

int main()
{
	bstNode n1;
	bstNode *root = NULL;
	int n;
	cout<<"Enter the number of elements you want to enter"<<endl;
	cin>>n;
	int val;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the item to insert"<<endl;
		cin>>val;
		root = n1.Insert(root,val);
	}
	cout<<"Preorder scheme of the tree:\n";
	n1.preorder(root);
	cout<<endl;
	cout<<"Inorder scheme of the tree:\n";
	n1.inorder(root);
	cout<<endl;
	cout<<"Postorder scheme of the tree:\n";
	n1.postorder(root);
	cout<<endl;
	cout<<"Levelorder scheme of the tree:\n";
	n1.levelorder(root);
	cout<<endl;
	// val=0;
	// cout<<"Number of leaf nodes in the tree = "<<n1.countLeaves(root,val)<<endl;
	 bstNode* newRoot = n1.Copy(root);
	// cout<<"Copy of the tree:(Preorder scheme)\n";
	// n1.preorder(newRoot);
	// cout<<endl;
	// cout<<"Minimum element in the tree: "<<n1.findMin(root)<<endl;
	// cout<<"Maximum element in the tree: "<<n1.findMax(root)<<endl;
	// cout<<"Height of the tree is: "<<n1.height(root)<<endl;
	// cout<<"Enter the value of the node to be created"<<endl;
	// cin>>val;
	// root = n1.insertNode(root,val);
	// cout<<"Inorder scheme of the tree after node insertion\n";
	// n1.inorder(root);
	// cout<<endl;
	// cout<<"Enter the node to be deleted\n";
	// cin>>val;
	// n1.deleteNode(root,val);
	// cout<<"Inorder scheme of the tree after node deletion\n";
	// n1.inorder(root);
	// cout<<endl;
	// cout<<"Comparison of two trees: \n";
	// if(n1.compare(root,newRoot) == 1)
	// 	cout<<"Trees are same!\n";
	// else
	// 	cout<<"Trees are different!\n";
	// cout<<"Enter the element to be searched\n";
	// cin>>val;
	// if(n1.Search(root,val) == true)
	// 	cout<<"Element found!\n";
	// else
	// 	cout<<"Element not found!\n";
	cout<<"Enter the node whose ancestors are to be printed\n";
	cin>>val;
	n1.printAncestors(root,val);
	cout<<endl;
	cout<<"Enter the node whose parent is to be printed\n";
	cin>>val;
	cout<<"Parent of the entered node:\n";
	n1.printParent(root,val,NULL);
	cout<<"Checking for mirror image:\n";
	if(n1.isMirror(root,newRoot))
	{
		cout<<"The two trees are mirror images of each other\n";
	}
	else
	{
		cout<<"The two trees are not mirror images of each other\n";
	}
	return 0;
}