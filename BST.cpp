#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
	int data;
	struct node *lchild,*rchild;

}*root=NULL;


struct node * insert(struct node *ptr,int value)
{
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->lchild=ptr->rchild=NULL;
		ptr->data=value;
		return ptr;
	}

	else if(value<ptr->data)
		ptr->lchild=insert(ptr->lchild,value);

	else if(value>ptr->data)
		ptr->rchild=insert(ptr->rchild,value);

	return ptr;
}
void search(struct node* ptr, int value)
{
	if(ptr!=NULL)
	{
		if(ptr->data==value)
		printf("Found! \n");

		else if(value<ptr->data)
			search(ptr->lchild,value);
		else if(value>ptr->data)
			search(ptr->rchild,value);
 	}
 	else
 	printf("Not found!!! \n");
}

struct node * del(struct node *root,int value)
{
	if(root==NULL)
		return root;
	else if(value<root->data)
		root->lchild=del(root->lchild, value);
	else if(value>root->data)
		root->rchild=del(root->rchild,value);

	else
	{
		struct node *temp=NULL;

		if(root->rchild==NULL)
			{
				temp=root->lchild;
				return temp;
			}

		else if(root->lchild==NULL)
			{
				temp=root->rchild;
				return temp;
			}

		else
		{
			temp=root->rchild;
			while(temp->lchild!=NULL)
			temp=temp->lchild;

			root->data=temp->data;
			root->rchild=del(root->rchild,temp->data);
		}

	}

	return root;

}

int height(struct node *root)
{
	if(root==NULL)
	return 0;

	int lh, rh;

	lh=height(root->lchild);
	rh=height(root->rchild);

	if(lh>rh)
	return ++lh;
	else
	return ++rh;

}


void inorder(struct node* root)
{
	if(root==NULL)
	return;

	inorder(root->lchild);
	printf("%d \t",root->data);
	inorder(root->rchild);

}

int main()
{
	int choice,value;

	while(1)
	{

		printf("Enter your choice : \n 1.Insert Node \n 2.Search \n 3.Delete \n 4.Display(inorder) \n 5.Height \n 6.Exit \n");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:	printf("Enter the value to be inserted \n");
					scanf("%d",&value);
					root=insert(root,value);
					printf("Node inserted \n");
					break;

			case 2:	printf("Enter the element to be searched \n");
					scanf("%d",&value);
					search(root,value);
					break;

			case 3:	printf("Enter the element to be deleted \n");
					scanf("%d",&value);
					root=del(root,value);
					break;

			case 4: inorder(root);
					break;

			case 5:	printf("Height  : %d",height(root));
					break;

			case 6: exit(0);

			default: printf("Wrong input! Try again!!! \n");

		}

	}

}

