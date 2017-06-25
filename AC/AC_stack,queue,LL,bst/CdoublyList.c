#include<stdio.h>
#include<stdlib.h>


typedef struct node{
int x;
struct node*l,*r;
}dll;



void create(dll**h)
{
(*h) = malloc(sizeof(dll));
(*h)->l=(*h);
(*h)->r=(*h);
(*h)->x=-1;
}
void display(dll*h)
{printf("\n%d",h->x);
 dll*t;
 t=h->r;
 while(t!=h)
{printf("%d",t->x);
t=t->r;
}
}

void insert(dll**h,int x)
{if((*h)->x==-1)
 {(*h)->x=x;
  }
 else
 {dll * temp = malloc(sizeof(dll));
  temp->r=(*h);
 temp->l=(*h)->l;
((*h)->l)->r=temp;
(*h)->l=temp;
(*h) = temp;
temp->x=x;

}
}



void main()
{
dll*h1,*h2,*h3,*t1,*t2,*t3;
create(&h1);
create(&h2);
printf("enter no. of digits for x and y\n");
int x,y;
int n;

scanf("%d %d",&x,&y);
int i;
printf("\nstarting from msb enter digits for num1 ");

for(i=0;i<x;i++)
{
printf("\nenter dig for num1 ");
scanf("%d",&n);
insert(&h1,n);
}

printf("\nstarting from msb enter digits for num1 ");
for(i=0;i<y;i++)
{
printf("\nenter dig for num2 ");
scanf("%d",&n);
insert(&h2,n);
}

create(&h3);
int c=0;
t1=h1;
t2=h2;
t3=h3;


for(i=0;i<x&&i<y;i++)
{int sum =0;
 sum = t1->x + t2->x + c;
 c = sum/10;
 t1=t1->r;
t2=t2->r;
 insert(&h3,sum%10);
}

if(x!=y)
{if(x<y)
 {for(i=x;i<y;i++)
 {int sum =0;
 sum = 0 + t2->x + c;
 c = sum/10;
 t2 = t2->r;
 insert(&h3,sum%10);
 }}
 else
{for(i=y;i<x;i++)
 {int sum =0;
 sum = 0 + t1->x + c;
 c = sum/10;
 t1=t1->r;
 insert(&h3,sum%10);}}}


display(h3);
}
