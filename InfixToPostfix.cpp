#include <iostream>
#include <cctype>
#define MAX 20

using namespace std;

class Stack
{
private:
	int top;
	int arr[MAX];
public:
	Stack()
	{
		top = -1;
	}
	void push(int);
	int pop();
	int isOperand(char);
	int precedence(char);
	int infixToPostfix(char*);
	int peek();
	int isEmpty();
	int evaluatePostfix(char*);
};

void Stack::push(int num)
{
	if(top == MAX-1)
	{
		cout<<"Stack Overflow!\n";
		return;
	}
	else
	{
		arr[++top] = num;
	}
}

int Stack::pop()
{
	if(top == -1)
	{
		return -1;
	}
	else
	{
		return arr[top--];
	}
}

int Stack::isOperand(char ch)
{
	if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z') ||(ch>='1' && ch<='9'))
		return 1;
	else
		return 0;
}

int Stack::precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '/':
		case '*':return 2;
		case '^':return 3;
	}
	return -1;
}

int Stack::peek()
{
	return arr[top];
}

int Stack::isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int Stack::infixToPostfix(char inf[])
{
	char post[MAX];
	int j=0;
	for(int i=0;inf[i] != '\0';i++)
	{
		if(isOperand(inf[i]))
		{
			post[j] = inf[i];
			j++;
		}
		else if(inf[i] == '(')
		{
			push(inf[i]);
		}
		else if(inf[i] == ')')
		{
			while(isEmpty() != 1 && peek() != '(')
			{
				post[j] = pop();
				j++;
			}
			pop();
		}
		else
		{
			while(isEmpty() != 1 && precedence(inf[i])<=precedence(peek()))
			{
				post[j]	= pop();
				j++;			
			}
			push(inf[i]);
		}

	}
	while(isEmpty() != 1)
	{
		post[j] = pop();
		j++;
	}
	post[j] = '\0';
	for(int i=0;post[i]!='\0';i++)
	{
		cout<<post[i];
	}
	cout<<endl;
}

int Stack::evaluatePostfix(char post[])
{
	for(int i=0;post[i]!='\0';i++)
	{
		if(isdigit(post[i]))
			push(post[i]-'0');
		else
		{
			int val1 = pop();
			int val2 = pop();
			switch(post[i])
			{
				case '+':push(val2+val1);break;
				case '-':push(val2-val1);break;
				case '*':push(val2*val1);break;
				case '/':push(val2/val1);break;
			}
		}
	}	
	return pop();
}

int main()
{
	Stack s;
	char inf[MAX];
	cout<<"Enter an infix string\n";
	cin>>inf;
	cout<<"Postfix string:\n";
	s.infixToPostfix(inf);
	cout<<"Enter the postfix string to be evaluated\n";
	char arr[MAX];
	cin>>arr;
	cout<<"Result: "<<s.evaluatePostfix(arr);
	return 0;
}