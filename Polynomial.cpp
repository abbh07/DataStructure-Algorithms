#include <iostream>
#include <cstdlib>

using namespace std;

class Polynomial
{
private:
	int constant;
	int exponent;
	Polynomial* next;
public:
	Polynomial()
	{
		constant=exponent=0;
		next=NULL;
	}
	Polynomial* insert(Polynomial*,int,int);
	void display(Polynomial*);
	Polynomial* add(Polynomial*,Polynomial*);
};

Polynomial* Polynomial::insert(Polynomial* po,int c,int e)
{
	Polynomial* p = new Polynomial();
	p->constant=c;
	p->exponent=e;
	p->next=NULL;
	Polynomial* h = po;
	if(po==NULL)
	{
		po=h=p;
	}
	else
	{
		while(po->next!=NULL)
		{
			po=po->next;
		}
		po->next=p;
	}
	return h;
}

void Polynomial::display(Polynomial* po)
{
	if(po==NULL)
	{
		cout<<"Empty List!\n";
	}
	else
	{
		while(po!=NULL)
		{
			cout<<po->constant<<"X^"<<po->exponent<<"+";
			po=po->next;
		}
		cout<<endl;
	}
}

Polynomial* Polynomial::add(Polynomial* h1,Polynomial* h2)
{
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	Polynomial* h3=NULL;
	Polynomial* three ;
	Polynomial* temp;
	while(h1!=NULL && h2!=NULL)
	{
		temp = new Polynomial();
		if(h1->exponent==h2->exponent)
		{
			temp->exponent=h1->exponent;
			temp->constant=(h1->constant+h2->constant);
			temp->next=NULL;
			h1=h1->next;
			h2=h2->next;
		}
		else if(h1->exponent>h2->exponent)
		{
			temp->exponent=h1->exponent;
			temp->constant=h1->constant;
			temp->next=NULL;
			h1=h1->next;
		}
		else if(h2->exponent>h1->exponent)
		{
			temp->exponent=h2->exponent;
			temp->constant=h2->constant;
			temp->next=NULL;
			h2=h2->next;
		}
		if(h3==NULL)
		{
			h3=three=temp;
		}
		else
		{
			h3->next=temp;
			h3=h3->next;
		}
	}
	while(h1!=NULL)
	{
		temp=new Polynomial();
		temp->next=NULL;
		temp->constant=h1->constant;
		temp->exponent=h1->exponent;
		h3->next=temp;
		h3=h3->next;
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		temp=new Polynomial();
		temp->next=NULL;
		temp->constant=h2->constant;
		temp->exponent=h2->exponent;
		h3->next=temp;
		h3=h3->next;
		h2=h2->next;
	}
	return three;
}

int main()
{
	Polynomial *head1=NULL,*head2=NULL,*head3=NULL;
	Polynomial p;
	cout<<"Enter the number of elements in the first polynomial\n";
	int n;
	cin>>n;
	int e;
	int c;
	while(n>0)
	{
		cout<<"Enter the exponent\n";
		cin>>e;
		cout<<"Enter the constant\n";
		cin>>c;
		head1=p.insert(head1,c,e);
		n--;
	}
	cout<<"Enter the number of elements in the second polynomial\n";
	cin>>n;
	while(n>0)
	{
		cout<<"Enter the exponent\n";
		cin>>e;
		cout<<"Enter the constant\n";
		cin>>c;
		head2=p.insert(head2,c,e);
		n--;		
	}
	cout<<"First Polynomial:\n";
	p.display(head1);
	cout<<"Second Polynomial:\n";
	p.display(head2);
	head3 = p.add(head1,head2);
	cout<<"Result after addition:\n";
	p.display(head3);
	return 0;
}