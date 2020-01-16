#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
char ssn[25], name[25], dept[10], designation[25];
int sal;
long int phoneno;
struct node *llink;
struct node *rlink;
};
typedef struct node* NODE;
NODE first = NULL;
int count = 0;
NODE createEmployeeNode()
{
char ssn[25], name[25], dept[10], designation[25];
int sal;
long int phoneno;
printf("\nEnter the ssn,Name,Department,Designation,Salary,PhoneNo of the employee: \n");
scanf("%s %s %s %s %d %ld",ssn,name,dept,designation,&sal,&phoneno);
NODE employeeNode;
employeeNode = (NODE)malloc(sizeof(struct node));
if( employeeNode== NULL)
{
printf("\nRunning out of memory");
exit(0);
}
employeeNode->llink = NULL;
employeeNode->rlink = NULL;
strcpy(employeeNode->ssn, ssn);
strcpy(employeeNode->name, name);
strcpy(employeeNode->dept, dept);
strcpy(employeeNode->designation, designation);
employeeNode->sal = sal;
employeeNode->phoneno = phoneno;
count++;
return employeeNode;
}
NODE insertAtFront()
{

NODE temp;
temp = createEmployeeNode();
if(first == NULL)
{
return temp;
}
temp->rlink = first;
first->llink = temp;
return temp;
}
NODE deleteAtFront()
{
NODE temp;
if(first == NULL)
{
printf("\nDoubly Linked List is empty");
return NULL;
}
if(first->rlink== NULL)
{
printf("\nThe employee node with the ssn:%s is deleted", first->ssn);
free(first);
count--;
return NULL;
}
temp = first;
first = first->rlink;
temp->rlink = NULL;
first->llink = NULL;
printf("\nThe employee node with the ssn:%s is deleted", temp->ssn);
free(temp);
count--;
return first;
}
NODE insertAtEnd()
{
NODE cur, temp;
temp = createEmployeeNode();
if(first == NULL)
{
return temp;
}
cur = first;
while(cur->rlink!=NULL)
{
cur = cur->rlink;
}
cur->rlink = temp;
temp->llink = cur;
return first;
}
NODE deleteAtEnd()

{
NODE prev, cur;
if(first == NULL)
{
printf("\nDoubly Linked List is empty");
return NULL;
}
if(first->rlink == NULL)
{
printf("\nThe employee node with the ssn:%s is deleted", first->ssn);
free(first);
count--;
return NULL;
}
prev = NULL;
cur = first;
while(cur->rlink!=NULL)
{
prev = cur;
cur = cur->rlink;
}
cur->llink = NULL;
printf("\nThe employee node with the ssn:%s is deleted", cur->ssn);
free(cur);
prev->rlink = NULL;
count--;
return first;
}
void displayStatus()
{
NODE cur;
int nodeno=1;
cur = first;
if(cur == NULL)
printf("\nNo Contents to display in DLL");
while(cur!=NULL)
{
printf("\nENode:%d|| SSN:%s| Name:%s| Department:%s| Designation:%s|
Salary:%d| Phone no:%ld", nodeno, cur->ssn, cur->name, cur->dept,
cur->designation, cur->sal, cur->phoneno);

cur = cur->rlink;
nodeno++;
}
printf("\nNo of employee nodes is %d",count);
}
void doubleEndedQueueDemo()
{
int ch;
while(1)
{
printf("\nDemo Double Ended Queue Operation");

printf("\n1:InsertQueueFront \n2: DeleteQueueFront \n3:InsertQueueRear

\n4:DeleteQueueRear \n5:DisplayStatus \n6: Exit \n");

scanf("%d", &ch);
switch(ch)
{
case 1: first = insertAtFront();
break;
case 2: first = deleteAtFront();
break;
case 3: first = insertAtEnd();
break;
case 4: first = deleteAtEnd();

break;
case 5: displayStatus();
break;
default : return;
}
}
}
void main()
{
int ch, i, n;
while(1)
{
printf("\n\n~~~Menu~~~");
printf("\n1:Create DLL of Employee Nodes");
printf("\n2:DisplayStatus");
printf("\n3:InsertAtEnd");
printf("\n4:DeleteAtEnd");
printf("\n5:InsertAtFront");
printf("\n6:DeleteAtFront");
printf("\n7:Double Ended Queue Demo using DLL");
printf("\n8:Exit\n");
printf("\nPlease enter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1 : printf("\nEnter the no of Employees: ");
scanf("%d", &n);
for(i=1;i<=n;i++)
first = insertAtEnd();
break;
case 2: displayStatus();
break;
case 3: first = insertAtEnd();
break;
case 4: first = deleteAtEnd();
break;
case 5: first = insertAtFront();
break;
case 6: first = deleteAtFront();
break;

case 7: doubleEndedQueueDemo();
break;
case 8 : exit(0);

default: printf("\nPlease Enter the valid choice");
}
}
}
