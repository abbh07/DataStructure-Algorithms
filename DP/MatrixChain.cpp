#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix_chain(vector<int> &dim)
{
	int len = dim.size();
	vector< vector<int> > T(len,vector<int> (len));
	int result = 0;

	for(int l=2;l<len;l++)
	{
		for(int i=0;i<len-l;i++)
		{
			int j = i + l;
			T[i][j] = INT_MAX;
			for(int k=i+1;k<j;k++)
			{
				result = T[i][k] + T[k][j] + dim[i]*dim[k]*dim[j];
				if(result < T[i][j])
				{
					T[i][j] = result;
				}
			}
		}
	}
	return T[0][len-1];
}

int main()
{
	int len;
	cout<<"Enter the length of the dimension vector:"<<endl;
	cin>>len;
	vector<int> dimension(len);
	cout<<"Enter the dimensions:"<<endl;
	for(int i=0;i<len;i++)
	{
		cin>>dimension[i];
	}
	cout<<"Minimum multiplication cost: "<<matrix_chain(dimension)<<endl;
	return 0;
}