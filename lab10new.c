#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("out of memory\n");
		return NULL;
	}
	temp->llink=temp->rlink=NULL;
	return temp;
}

NODE insert(NODE root, NODE new)
{
	if(root==NULL)
	{
		return new;
	}
	if((new->info)<(root->info))
	{
		root->llink=insert(root->llink, new);
	}
	if((new->info)>=(root->info))
	{
		root->rlink=insert(root->rlink, new);
	}
	return root;
}

void search(NODE root, int ele)
{
	NODE temp=root;
	while(temp->info!=ele)
	{
		if((ele)<(temp->info))
			temp=temp->llink;
		else if((ele)>=(temp->info))
			temp=temp->rlink;
		if(temp==NULL)
		{
			printf("element not found\n");
			return;
		}
	}
	printf("element found\n");
}

void inorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);
}

void preorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void postorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d",root->info);
}

void main()
{
	NODE root=NULL, new;
	int choice, ele;
	for(;;)
	{
		printf("enter the choice\n1.insert\n2.search\n3.inorder\n4.preorder\n5.postorder\n6.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					new= getnode();
					printf("enter the element to be inserted\n");
					scanf("%d",&ele);
					new->info=ele;
					root=insert(root, new);
					break;
			case 2: printf("enter the element to be searched\n");
					scanf("%d",&ele);
					search(root, ele);
					break;
			case 3: inorder(root);
					break;
			case 4: preorder(root);
					break;
			case 5: postorder(root);
					break;
			case 6: exit(0);
		}
	}
}
