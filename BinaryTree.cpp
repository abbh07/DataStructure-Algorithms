	#include <iostream>

	using namespace std;

	class Tree
	{
	private:
		int data;
		Tree* lchild;
		Tree* rchild;
	public:
		Tree()
		{
			lchild = rchild = NULL;
		}
		Tree* create();
		void preorderIterative(Tree*);
		void postorderIterative(Tree*);
	};

	Tree* Tree::create()
	{
		int val;
		Tree* temp;
		cin>>val;
		if(val == -1)
			return NULL;
		else
		{
			temp = new Tree();
			temp->data = val;
			temp->lchild = create();
			temp->rchild = create();
			return temp;
		}
	}

	void Tree::preorderIterative(Tree* root)
	{
		Tree* cur;
		Tree* arr[20];
		int top = -1;
		if(root == NULL)
		{
			cout<<"Tree Empty!\n";
			return;
		}
		else
		{
			cur = root;
			while(1)
			{
				while(cur != NULL)
				{
					cout<<cur->data<<"\t";
					arr[++top] = cur;
					cur = cur->lchild;
				}
				if(top != -1)
				{
					cur = arr[top--];
					cur = cur->rchild;
				}
				else
					return;
			}
		}
	}

	void Tree::postorderIterative(Tree* root)
	{
		Tree* arr1[20];
		Tree* arr2[20];
		int top1 = -1;
		int top2 = -1;
		arr1[++top1] = root;
		Tree* cur;
		while(top1 != -1)
		{
			cur = arr1[top1--];
			arr2[++top2] = cur;

			if(cur->lchild)
				arr1[++top1] = cur->lchild;
			if(cur->rchild)
				arr1[++top1] = cur->rchild;
		}
		while(top2 != -1)
		{
			cur = arr2[top2--];
			cout<<cur->data<<"\t";
		}
		cout<<endl;
		
	}

	int main(int argc, char const *argv[])
	{
		Tree t;
		cout<<"Enter the value for the nodes\n";
		Tree* root = t.create();
		cout<<"Preorder:\n";
		t.preorderIterative(root);
		cout<<endl;
		cout<<"Postorder:\n";
		t.postorderIterative(root);	
		return 0;
	}