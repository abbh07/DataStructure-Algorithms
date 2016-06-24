#include<conio.h>
#include<iostream.h>
#include<process.h>
class spm{public:
	   int r,c,val;

	   void read(spm *,int,int);
	   void display(spm*);
	   void trans(spm *,spm *);
	 };
void spm::read(spm a[],int m,int n)
{int item;
 a[0].r=m;
 a[0].c=n;
 int k=1;
 cout<<"enter items :-"<<endl;
 for(int i=0 ; i<m ; i++)
 {for(int j=0 ; j<n ; j++)
  {cin>>item;
   if(item==0)
    continue;
   a[k].r=i;
   a[k].c=j;
   a[k].val=item;
   k++;
  }
 }
 a[0].val=k-1;
}
void spm::display(spm a[])
{for(int i=1 ; i<=a[0].val ; i++)
 {cout<<a[i].r<<"\t"<<a[i].c<<"\t"<<a[i].val<<endl;}
}
void spm::trans(spm a[], spm b[])
{b[0].r=a[0].c;
 b[0].c=a[0].r;
 b[0].val=a[0].val;
 int k=1;
 for(int i=0; i<a[0].c ; i++)
 {for(int j=1 ; j<=a[0].val ; j++)
  {if(a[j].c==i)
   {b[k].r=a[j].c;
    b[k].c=a[j].r;
    b[k].val=a[j].val;
    k++;
   }
  }
 }
}
void main()
{spm a[50],b[50],obj;
 int i,j;
 clrscr();
 cout<<"enter rows and columns : "<<endl;
 cin>>i>>j;
 obj.read(a,i,j);
 cout<<"contents:-"<<endl;
 obj.display(a);
 obj.trans(a,b);
 cout<<"contents after transpose:-"<<endl;
 obj.display(b);
 getch();
}

