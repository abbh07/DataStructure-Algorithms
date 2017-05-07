/*
* Author: Aakash Bhattacharya
* Reference: http://www.cplusplus.com/reference/queue/queue/
*/

#include<bits/stdc++.h> 
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

int main()
{
	queue <int> q;
	while(true)
	{
		cout<<"Enter your choice: \n";
		cout<<"1.Enqueue  2.Dequeue  3.Dequeue & Display  4.Exit"<<endl;
		int choice;
		cin>>choice;
		int item;
		switch(choice)
		{
			case 1:
				cout<<"Enter a number to enqueue"<<endl;
				cin>>item;
				q.push(item);
				break;
			case 2:
				if(q.empty())
				{
					cout<<"Queue Empty!"<<endl;
				}			
				else
				{
					cout<<"Popped element: "<<q.front()<<endl;
					q.pop();
				}
				break;
			case 3:
				if(q.empty())
				{
					cout<<"Queue Empty!"<<endl;
				}
				else
				{
					cout<<"Queue contents:"<<endl;
					while(q.size() != 0)
					{
						cout<<q.front()<<endl;
						q.pop();
					}
				}
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}