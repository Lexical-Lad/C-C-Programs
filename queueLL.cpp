#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
	int data;
	struct node *next;

};

struct node * front=NULL, *rear=NULL;

void insert(int data);
void deletion();
void display();

int main()
{
	char c;
	int data;


	while(1)
	{

		printf("What do you want to do? \n a.Insert \n b.Delete \n c.Display\n d.Exit \n");

		scanf(" %c",&c);

		switch(c)

		{
			case 'a' : 	printf("Enter the value to be inserted \n");
						scanf(" %d",&data);

						insert(data);
						break;

			case 'b': 	deletion();
						break;

			case 'c': 	display();
						break;

			case 'd': 	exit(0);

			default : 	printf("Invalid Option. Try again\n");

		}

	}

}


void insert(int data)

{	struct node *new_n=(struct node*)malloc(sizeof(struct node));

	new_n->data=data;
	new_n->next=NULL;

	if(front==NULL)
		front=rear=new_n;

	else
		{
			rear->next=new_n;
			rear=new_n;
		}

	printf("Node inserted\n");


}

void deletion()
{
	if(front==NULL)
	{
		printf("The queue is empty\n");
		return;
	}

	struct node *temp=front;
	printf(" %d \n",front->data);

	front=front->next;

	free(temp);

}

void display()
{
	if(front==NULL)
	{
		printf("The queue is empty\n");
		return;
	}

	struct node *ptr=front;

	printf("Front -> \t");

	while(ptr!=NULL)
	{
		printf(" %d \t",ptr->data);

		ptr=ptr->next;
	}

	printf("<-Rear \n");


}











