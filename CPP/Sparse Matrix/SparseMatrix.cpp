	#include <iostream>
	#include <cstdlib>
	#define size 20

	using namespace std;

	class SparseMatrix
	{
	private:
		int r,c,v;
	public:
		SparseMatrix()
		{
			r=c=v=0;
		}
		void create(SparseMatrix*,int,int);
		void display(SparseMatrix*);
		void transpose(SparseMatrix*,SparseMatrix*);

	};

	void SparseMatrix::create(SparseMatrix arr[],int m,int n)
	{
		arr[0].r=m;
		arr[0].c=n;
		int k=1;
		int ele;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"Enter the element to be inserted\n";
				cin>>ele;
				if(ele!=0)
				{
					arr[k].r=i;
					arr[k].c=j;
					arr[k].v=ele;
					k++;				
				}
			}
		}
		arr[0].v=k-1;
	}

	void SparseMatrix::display(SparseMatrix arr[])
	{
		int k=arr[0].v;
		for(int i=0;i<=k;i++)
		{
			cout<<arr[i].r<<"\t"<<arr[i].c<<"\t"<<arr[i].v<<endl;
		}
	}

	void SparseMatrix::transpose(SparseMatrix arr[],SparseMatrix arr1[])
	{
		arr1[0].r=arr[0].c;
		arr1[0].c=arr[0].r;
		arr1[0].v=arr[0].v;
		int k=1;
		if(arr[0].v>0)
		{
			for(int i=0;i<arr[0].c;i++)
			{
				for(int j=0;j<=arr[0].v;j++)
				{
					if(arr[j].c==i)
					{
						arr1[k].r=arr[k].c;
						arr1[k].c=arr[k].r;
						arr1[k].v=arr[k].v;
						k++;
					}
				}
			}
		}
	}

	int main()
	{
		SparseMatrix sm,arr[size];
		cout<<"Enter the number of rows and columns\n";
		int m,n;
		cin>>m>>n;
		sm.create(arr,m,n);
		cout<<"Elements of the sparse matrix:\n";
		sm.display(arr);
		SparseMatrix arr1[size];
		cout<<"Transpose of the entered matrix:\n";
		sm.transpose(arr,arr1);
		sm.display(arr1);
		return 0;
	}