#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string arr;
	cout<<"Enter a string:\n";
	cin>>arr;
	stack <char> s;
	for(int i=0;i<arr.length();i++)
	{
		s.push(arr[i]);
	}
	for(int i=0;i<arr.length();i++)
	{
		char poppedElement = s.top();
		s.pop();
		if(arr[i] != poppedElement)
		{
			break;
		}
	}
	if(s.empty())
	{
		cout<<"The entered string is a palindrome!"<<endl;
	}
	else
	{
		cout<<"The entered string is not a palindrome!"<<endl;
	}
	return 0;
}