#include<stdio.h>
#include<stdlib.h>
int itm;
struct node 
{
int info;
struct node *rlink;
struct node *llink;
};
typedef struct node *NODE;
NODE create()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
if(temp==NULL)
return NULL;
temp->rlink=temp->llink=NULL;
return temp;
}
NODE insertn(NODE new,NODE root)
{

if(root==NULL)
return new;
if((new->info) < (root->info))
root->llink=insertn(new,root->llink);
else
root->rlink=insertn(new,root->rlink);
return root;
}
NODE search(int itm,NODE root)
{

if(root==NULL||root->info==itm)
return root;
if(itm< root->info)
return search(itm,root->llink);
return search(itm,root->rlink);
}
void preorder(NODE root)
{while(root!=NULL)
{
printf("\n%d ",root->info);
preorder(root->llink);
preorder(root->rlink);return;}}
void inorder(NODE root)
{

inorder(root->llink);
printf("\n%d ",root->info);
inorder(root->rlink);
return;
}
void postorder(NODE root)
{
if(root!=NULL){
postorder(root->llink);

postorder(root->rlink);
printf("\n %d ",root->info);
return;}}

void main()
{
NODE root=NULL,new,temp;
int ch;

while(1){
printf("\n1.Insert\n2.Preorder\n3.inorder\n4.postorder\n5.search\n6.exit\n");
printf("Enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter item");
scanf("%d",&itm);
new->info=itm;
 root=insertn(itm,root);
break;
case 2:while(root!=NULL)
 preorder(root);
break;
case 3: 
while(root!=NULL)
inorder(root);
break;
case 4:
while(root!=NULL)
postorder(root);
break;
case 5:printf("Enter item to be searched");
scanf("%d",&itm);
temp=search(itm,root);
if(temp==NULL)

printf("Element not found");
else 
printf("Element found");
break;
case 6:exit(0);
default:printf("\nWrong choice");
}
}

}
