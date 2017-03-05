#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node
{
	char data;
	struct node *lchild,*rchild;
}*root=NULL;

void create(struct node *parent)
{
	if(parent!=NULL)
	{
		struct node *t;
		char ch='\0';
		printf("Do you want to enter left child for %c?(y/n) \n",parent->data);
		fflush(stdin);
		scanf(" %c",&ch);

		if(ch=='y')
		{	t=(struct node *)malloc(sizeof(struct node));
			printf("Enter the value for the left child \n");
			fflush(stdin);

			scanf(" %c",&t->data);
			parent->lchild=t;

			create(t);
		}
		else
		parent->lchild=NULL;


		t=NULL;
		printf("Do you want to enter right child for %c?(y/n) \n",parent->data);
		fflush(stdin);
		scanf(" %c",&ch);

		if(ch=='y')
		{	t=(struct node *)malloc(sizeof(struct node));
			printf("Enter the value for the right child \n");
			fflush(stdin);


			scanf(" %c",&t->data);
			parent->rchild=t;

			create(t);
		}
		else
		parent->rchild=NULL;


	}

}

/* void preorderRec(struct node *root)
{
	if(root==NULL)
	return;

	printf("%c \n",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void inorderRec(struct node *root)
{
	if(root==NULL)
	return;

	inorder(root->lchild);
	printf("%c \n",root->data);
	inorder(root->rchild);

}

void postorderRec(struct node *root)
{
	if(root==NULL)
	return;

	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c \t",root->data);
} */

void preorder()
{

	struct node *stack[1000],*temp;

	int count=-1;

	stack[++count]=NULL;

	stack[++count]=root;

	while(stack[count]!=NULL)
	{
		printf("%c",stack[count]->data);
		temp=stack[count];

		count--;
		if(temp->rchild!=NULL)
		stack[++count]=temp->rchild;

		if(temp->lchild!=NULL)
		stack[++count]=temp->lchild;
	}

}

void inorder()
{
	struct node *stack[1000],*current=NULL;
	int count=-1;

	stack[++count]=NULL;

	current=root;

	while(1)
	{
		while(current!=NULL)
		{
			stack[++count]=current;
			current=current->lchild;
		}

		if(current==NULL && stack[count]!=NULL)
		{
		current=stack[count]->rchild;
		printf("%c",stack[count]->data);
		count--;
		}
		else
		break;
	}

}


void postorder()
{
	struct node *stack1[1000],*stack2[1000],*temp;

	int count1=-1,count2=-1;

	stack1[++count1]=NULL;
	stack2[++count2]=NULL;

	stack1[++count1]=root;

	while(stack1[count1]!=NULL)
	{
		stack2[++count2]=stack1[count1];
		temp=stack1[count1];
		count1--;
		if(temp->lchild!=NULL)
		stack1[++count1]=temp->lchild;
		if(temp->rchild!=NULL)
		stack1[++count1]=temp->rchild;
	}

	while(stack2[count2]!=0)
	{
		printf("%c",stack2[count2]->data);
		count2--;
	}
}


int main()
{
	int choice;
	printf("Creation time, bitches!!!) \n");

	printf("Enter the value for the root \n");

	root=(struct node*)malloc(sizeof(struct node));

	scanf(" %c",&root->data);

	create(root);

	printf("Tree created \n");


	while(1)
	{
		printf("Enter your choice :\n 1.Insert an element \n 2.Find the Height \n 3.Preorder Print \n 4.Inorder Print \n 5.Postorder print \n 6.exit \n");
		scanf("%d",&choice);

		switch(choice)
		{
			//case 1:	insert();
					//break;

			//case 2:	height();
					//break;

			case 3:	preorder();
					break;

			case 4:	inorder();
					break;

			case 5:	postorder();
					break;

			case 6:	exit(0);

			default: printf("Invalid Input. Try Again!!!\n");
		}

	}

}

