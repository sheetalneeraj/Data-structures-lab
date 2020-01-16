#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node 
{
int cf;
int px,py,pz;
struct node *link;
};
typedef struct node *NODE;

void display(NODE head)
{NODE cur;
if(head->link==head)
{
printf("\nPolynomial doesn't exist");
return;
}
cur=head->link;
while(cur!=head)
{
if(cur->cf>0)
printf(" + ");
printf("%d",cur->cf);
printf("x^%d y^%d z^%d",cur->px,cur->py,cur->pz);
cur=cur->link;
}
}
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
return NULL;
return x;
}
NODE insertr(int cf,int px,int py,int pz,NODE head)
{
NODE cur, temp;
temp=getnode();
temp->cf=cf;
temp->px=px;
temp->py=py;
temp->pz=pz;
temp->link=NULL;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}

 NODE readp(NODE head)
{
int i,j,px,py,pz,n,cf;
printf("Enter no of terms");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
printf("\nTERM %d",i);
printf("\nEnter coefficient ");
scanf("%d",&cf);
printf("Enter powers of X ,Y ,Z");
scanf("%d %d %d",&px,&py,&pz);
head=insertr(cf,px,py,pz,head);
}
return head;
}
void evaluate(NODE head)
{int res,x,y,z;
NODE cur;
if(head->link==head)
{
printf("\nPolynomial doesn't exist");
return ;
}
cur=head->link;
printf("\nEnter values of X,Y,Z");
scanf("%d %d %d",&x,&y,&z);
while(cur!=head)
{
res=res+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
cur=cur->link;
}
printf("Result= %d\n",res);
}
NODE add(NODE h1,NODE h2,NODE h3)
{
NODE p1,p2;
int cf;
p1=h1->link;
p2=h2->link;
while(p1!=h1&&p2!=h2)
{
if(p1->px>p2->px)
{
h3=insertr(p1->cf,p1->px,p1->py,p1->pz,h3);
p1=p1->link;
}
else if(p1->px<p2->px)
{
h3=insertr(p2->cf,p2->px,p2->py,p2->pz,h3);
p2=p2->link;
}
else if(p1->py>p2->py)
{
h3=insertr(p1->cf,p1->px,p1->py,p1->pz,h3);
p1=p1->link;
}
else if(p1->py<p2->py)
{
h3=insertr(p2->cf,p2->px,p2->py,p2->pz,h3);
p2=p2->link;}
else if(p1->pz>p2->pz)
{
h3=insertr(p1->cf,p1->px,p1->py,p1->pz,h3);
p1=p1->link;
}
else if(p1->pz<p2->pz)
{
h3=insertr(p2->cf,p2->px,p2->py,p2->pz,h3);
p2=p2->link;}
else 
{
int sum=p1->cf+ p2->cf;
h3=insertr(sum,p1->px,p1->py,p1->pz,h3);
p1=p1->link;
p2=p2->link;
}
}
while(p1!=h1)
{
h3=insertr(p1->cf,p1->px,p1->py,p1->pz,h3);
p1=p1->link;
}

while(p2!=h2)
{
h3=insertr(p2->cf,p2->px,p2->py,p2->pz,h3);
p2=p2->link;
}
return h3;
}
void main()
{int ch;
NODE h1,h2,h3;
h1=getnode();
h2=getnode();
h3=getnode();
h1->link=h1;
h2->link=h2;
h3->link=h3;
while(1)
{
printf("\n\n 1. Represent and evaluate polynomial\n 2.Add two polynomials \n 3. exit \n"); 
scanf("%d",&ch);
switch(ch)
{case 1:  h1=readp(h1);
display(h1);
evaluate (h1);
break;
case 2:
printf("Enter first polynomial");
h1=readp(h1);
printf("Enter second polynomial");
h2=readp(h2);
h3= add(h1,h2,h3);
printf("\nThe first polynomial is");
display(h1);
printf("\nThe second polynomial is");
display(h2);
printf("\n\nThe sum is \t ");
display(h3);
break;
case 3:exit(0);
default: printf("Wrong choice");
}}}
