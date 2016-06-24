#include<iostream.h>
#include<conio.h>
#include<process.h>
class cq{ int rear,front,count;
	  int item;
	  int q[20];
	 public:
	  cq()
	  {front=rear=count=0;}
	  void insert(int);
	  void del(int);
	  void display(int);
	};
void cq::insert(int n)
{if(count==n)
 {cout<<"Queue full!"<<endl;
  return;
 }
 cout<<"enter item to be inserted :"<<endl;
 cin>>item;
 rear = (rear+1)%n;
 q[rear]=item;
 count++;
}
void cq::del(int n)
{if(count==0)
 {cout<<"queue empty!"<<endl;
  return;
 }
 front = (front+1)%n;
 cout<<"the deleted item is : "<<q[front]<<endl;
 count--;
}
void cq::display(int n)
{if(count==0)
 {cout<<"queue empty!"<<endl;
  return;
 }
 int k=front+1;
 cout<<"contents :- "<<endl;
 for(int i=1; i<=count ; i++)
 {cout<<q[k]<<"\t";
  k=(k+1)%n;
 }
 cout<<endl;
}
void main()
{int it,i,j,ch,size;
 cq obj;
 clrscr();
 cout<<"enter size : "<<endl;
 cin>>size;
 while(1)
 {cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
  cout<<"enter a choice"<<endl;
  cin>>ch;
  switch(ch)
  {case 1 : obj.insert(size);break;
   case 2 : obj.del(size);break;
   case 3 : obj.display(size);break;
   case 4 : exit(0); break;
   default : cout<<"wrong choice";
  }
  getch();
 }
}

