#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char usn[10];
char name[20];
char branch[20];
int sem;
char phno[20];
struct node *link;
};
typedef struct node *NODE;
//INSERTION AND DELETION AT FRONT
NODE insertf(char usn[],char name[],char branch[],int sem, char phno[],NODE first)
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
strcpy(temp->usn,usn);
strcpy(temp->name,name);
strcpy(temp->branch,branch);
temp->sem=sem;
strcpy(temp->phno,phno);
temp->link=first;
return temp;
}

NODE deletef(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("NO NODE");
return first;
}
temp=first;
first=first->link;
printf("Following data is deleted");
printf("\n usn : %s \n name : %s \n branch : %s \n sem : %d\n phno : %s", temp->usn, temp->name,temp->branch, temp->sem, temp->phno);
free(temp);
return (first);
}
//INSERTION AND DELETION AT REAR 
NODE insertr(char usn[],char name[],char branch[],int sem, char phno[],NODE first)
{
NODE temp,cur;
temp=(NODE)malloc(sizeof(struct node));
strcpy(temp->usn,usn);
strcpy(temp->name,name);
strcpy(temp->branch,branch);
temp->sem=sem;
strcpy(temp->phno,phno);
temp->link=NULL;
if(first==NULL)
return temp;

cur=first;
if(cur->link!=NULL)
{
cur=cur->link;
}
cur->link=temp;
return first;
}
NODE deleter(NODE first)
{
NODE cur,prev;
if(first==NULL)
{
printf("No node");
return first;
}
if(first->link==NULL)
{
printf("Following data is deleted");
printf("\n usn : %s \n name : %s \n branch : %s \n sem : %d\n phno : %s", first->usn, first->name,first->branch, first->sem, first->phno);
free(first);
return NULL;
}
prev=NULL;
cur=first;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
printf("Following data is deleted");
printf("\n usn : %s \n name : %s \n branch : %s \n sem : %d\n phno : %s", cur->usn, cur->name,cur->branch, cur->sem, cur->phno);
free(cur);
prev->link=NULL;
return first;
}
void display(NODE first)
{
NODE cur;
int c=0;
if(first==NULL)
{
return ;
}
cur=first;
while(cur!=NULL)
{c=c+1;
printf("\n usn : %s \n name : %s \n branch : %s \n sem : %d\n phno : %s", cur->usn, cur->name,cur->branch, cur->sem, cur->phno);
cur=cur->link;
}
printf("\nNumber nodes=%d",c);
}
 void main()
{
NODE first=NULL;
int ch,sem;
char u[20],n[20],b[20],ph[20];
int no;
printf("Enter no of students");
scanf("%d",&no);
for(int i=0;i<=no;i++)
{printf("Enter usn ,name ,branch , phno ,sem");
scanf("%s",u);
scanf("%s",n);
scanf("%s",b);
scanf("%s",ph);
scanf("%d",&sem);
first=insertf(u,n,b,sem,ph,first);
}
printf("\n1. insert at front\n2.delete at front\n3.insert at rear\n4.delete st rear\n5.display\n6.exit\n\nEnter choice");
scanf("%d",&ch);
while(1)
{
switch(ch)
{
case 1:printf("Enter usn, name,branch phone no and semester respectively");
scanf("%s",u);
scanf("%s",n);
scanf("%s",b);
scanf("%s",ph);
scanf("%d",&sem);
first=insertf(u,n,b,sem,ph,first);
break;
case 2:deletef(first);
break;
case 3:printf("\nEnter usn=%s",u);
scanf("\nEnter name=%s",n);
scanf("\nEnter branch=%s",b);
scanf("\nEnter phno=%s",ph);
scanf("\nEnter sem=%d",&sem);
first=insertr(u,n,b,sem,ph,first);
break;
case 4:deleter(first);
break;
case 5:display(first);
break;
case 6:exit(0);
default:printf("\nWrong choice");
}}
}





