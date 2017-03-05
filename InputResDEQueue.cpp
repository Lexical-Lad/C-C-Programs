#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


//insertion only allowed at the end

struct node
{
	struct node *next,*prev;
	int data;
};

typedef struct node node;

node *start=NULL,*end=NULL; //start->end = left->right

void insert_end(int data);
void delete_beg();
void delete_end();
void display();


int main()
{
	char c;
	int data;

	while(1)
	{
		printf("What do you want to do? \n a.Insert \n b.Delete(first element) \n c.Delete(last element) \n d.Display Queue \n e.Exit\n");
		scanf(" %c",&c);

		switch(c)
		{
			case 'a' :	printf("Enter the element to be inserted\n");
						scanf("%d",&data);

						insert_end(data);
						printf("Element inserted \n");
						break;

			case 'b' :	delete_beg();
						break;

			case 'c' :	delete_end();
						break;

			case 'd' :	display();
						break;

			case 'e' :	exit(0);

			default  :	printf("Invalid Input. Please try again\n");

		}

	}


}

void insert_end(int data)
{
	node *new_node=(node *)malloc(sizeof(node));

	new_node->data=data;

	if(start==NULL)
	{
		start=end=new_node;
		start->next=start->prev=NULL;
	}

	else
	{
		new_node->prev=end;
		end->next=new_node;
		end=new_node;
		end->next=NULL;
	}

}

void delete_beg()
{
	node *temp;

	if(start==NULL)
	{
		printf("The queue is empty. Please insert at least one element before performing deletion \n");
		return;
	}

	temp=start;

	printf("The element deleted is : %d \n",start->data);

	if(start==end)
	{
		start=end=NULL;
		free(temp);
	}
	else
	{
		start=start->next;
		start->prev=NULL;
		free(temp);
	}

}


void delete_end()
{

	node *temp;

	if(start==NULL)
	{
		printf("The queue is empty. Please insert at least one element before performing deletion \n");
		return;
	}

	temp=end;

	printf("The element deleted is : %d \n",end->data);

	if(start==end)
	{
		start=end=NULL;
		free(temp);
	}
	else
	{
		end=end->prev;
		end->next=NULL;
		free(temp);
	}

}


void display()
{
	node *temp;

	if(start==NULL)
	{
		printf("The queue is empty. Nothing to display \n");
		return;
	}

	temp=start;

	while(temp!=end)
	{
		printf("%d -> ",temp->data);

		temp=temp->next;

	}
	printf("%d \n",temp->data);

}




