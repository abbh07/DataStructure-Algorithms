//Program to compute all the factors of a number
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> factors;

	//Primitive method by looping until n/2 
	//There are no factors of a number n greater than n/2 other than n
	for(int i = 1;i<=n/2;i++)
	{
		if(n%i==0)
		{
			factors.push_back(i);
		}
	}
	factors.push_back(n);

	for(int i=0;i<factors.size();i++)
	{
		cout<<factors[i]<<" ";
	}
	cout<<endl;
	factors.clear();

	//Optimized method by looping until sqrt(n)
	//This follows from the fact that a*b = n, where a & b are the cofactors of n
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i == 0)
		{
			factors.push_back(i);
			if(i!=sqrt(n))
				factors.push_back(n/i);
		}
	}


	for(int i=0;i<factors.size();i++)
	{
		cout<<factors[i]<<" ";
	}
	cout<<endl;
	return 0;
}