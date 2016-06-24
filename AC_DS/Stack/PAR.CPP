#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class Par
{
	public:
	int top;
	int len;
	public: char str[30];
	int s[30];
	int max;
	public:
	void push();
	int pop();
	int check();
	Par()
	{
		top=-1;
		max=30;
	}
};
void Par :: push()
{
		if(top==(max-1))
	{
		cout<<"Stack is full\n";
		return;
	}
	s[++top]=1;
	cout<<"\n";
}
int Par :: pop()
{
	if(top==-1)
	{
		return 2;
	}
	cout<<"\n";
	return s[top--];
}
int Par :: check()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void main()
{
	clrscr();
	Par obj;
	int top;
	int k;
	char str[30];
	cout<<"Enter the expression to be checked.\n";
	gets(str);
	int l=strlen(str);
	for(int i=0;i<l;i++)
	{
		if(str[i]=='(')
		obj.push();
		else if(str[i]==')')
		{
			k=obj.pop();
			if(k==2)
			{cout<<"Not matching.\n";getch();
			return;
			}
		}
	}
	top=obj.check();
	if(top==1)
	cout<<"Matching\n";
	else
	cout<<"Not matching.\n";
	getch();
}
