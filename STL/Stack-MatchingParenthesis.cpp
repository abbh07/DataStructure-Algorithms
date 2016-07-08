#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cout<<"Enter a string:\n";
	string inputString;
	cin>>inputString;
	stack <char> stk;
	bool flag = 1;
	for(int i=0;i<inputString.length();i++)
	{
		if(inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{')
		{
			stk.push(inputString[i]);
		}
		if(inputString[i] == ')' || inputString[i] == ']' || inputString[i] == '}')
		{
			if(stk.empty())
			{
				flag = 0;
				break;
			}
			else
			{
				char poppedElement = stk.top();
				stk.pop();
				if(inputString[i] == ')' && poppedElement == '(')
					continue;
				if(inputString[i] == ']' && poppedElement == '[')
					continue;
				if(inputString[i] == '}' && poppedElement == '{')
					continue;
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if(i == (inputString.length()-1) && !stk.empty())
		{
			flag = 0;
			break;
		}
	}

	if(flag)
	{
		cout<<"Valid String!\n";
	}
	else
	{
		cout<<"Invalid String!\n";
	}
	return 0;
}