#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
class Pal
{
	int top;
	char str[20];
	char c;
	public:
	void push(char);
	char pop();
	Pal()
	{
		top=-1;
		max=20;
	}
};
void Pal :: push(char c)
{
	str[++top]=c;
	cout<<"\n";
}
char Pal :: pop()
{		
	if(top>=0)
	return str[top--];
}
void main()
{
	clrscr();getch();
	Pal obj;
	int n;char ch;
	int flag==0
	char wrd[100];
	cout<<"Enter word(max words 20)\n";
	gets(wrd);
	n=strlen(wrd);
	for(int i=0;i<n;i++)
	obj.push(str[i]);
	for(int j=0;j<n/2;j++)
	{	
		ch=obj.pop();
		if(ch!=wrd[j])
		{
			flag=1;
			break;
		}
		
	}
	if(flag == 1)
	cout<<"Not palindrome.\n";
	else
	cout<<"Palindrome.\n";
	getch();
}