#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cout<<"Enter the number to be converted:\n";
	int number;
	cin>>number;
	cout<<"Enter the base:\n";
	int base;
	cin>>base;
	stack <int> s;

	while(number>0)
	{
		s.push(number%base);
		number = number / base;
	}
	cout<<"Number after conversion:\n";
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
	return 0;
}