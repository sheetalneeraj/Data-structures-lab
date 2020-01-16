#include<stdio.h>
#include<stdlib.h>
int pos, itm,*a,i,n;

//CREATE
void create()
{
a=(int*)malloc(sizeof(int));
if(a==NULL)
printf("Array cannot be created");
printf("Enter number of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}

//DISPLAY
void display()
{
printf("\n The array elements:\n");
for(i=0;i<n;i++)
printf("\t%d",a[i]);
}

//INSERT
void insert()
{
if(n==0)
printf("No elements in array");
printf("\nEnter item to be inserted");
scanf("%d",&itm);
printf("Enter position where to be inserted");
scanf("%d",&pos);
if(pos<0|| pos>n)
printf("Invalid position");
for(i=n-1;i>=pos;i--)
a[i+1]=a[i];
 a[pos]=itm;
n=n+1;
}

//DELETE
void delete()
{
if(n==0)
{
printf("No elements in array");

return;}
printf("Enter position of item to be deleted");
scanf("%d",&pos);
if(pos<0|| pos>n)
{printf("Invalid position");
return;
}
printf("\n The item deleted is %d",a[pos]);
for(i=pos;i<n;i++)
a[i]=a[i+1];
n=n-1;
}

void main()
{
int ch=0;
while(ch!=5)
{
printf("\n\t\t---ARRAY OPERATIONS---\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit");
printf("\n Enter choice ");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:insert();
break;
case 3:delete();
break;
case 4:display();
break;
case 5:exit(0);
default:printf("\nWrong choice");
}
}
}



