/*
* Author: Aakash Bhattacharya
* Reference: http://www.cplusplus.com/reference/stack/stack/
*/

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int main()
{
	stack <int> stk;
	while(true)
	{
		cout<<"Enter your choice:\n";
		cout<<"1.Push  2.Pop  3.Pop & Display  4.Exit\n";
		int choice;
		cin>>choice;
		int item;
		switch(choice)
		{
			case 1:
				cout<<"Enter a number to push\n";
				cin>>item;
				stk.push(item);
				break;
			case 2:
				if(stk.empty())
				{
					cout<<"Stack Empty!\n";
				}
				else
				{
					cout<<"Popped item: "<<stk.top()<<endl;
					stk.pop();
				}
				break;
			case 3:				
				if(stk.empty())
				{
					cout<<"Stack Empty!"<<endl;
				}
				else
				{
					cout<<"Stack Contents:\n";
					while(stk.size() != 0)
					{
						cout<<stk.top()<<endl;
						stk.pop();
					}
				}				
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}