#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;



void push(int data);
void pop();
void peep();


int main()
{	int data;
	char c;

	while(1)
	{
		printf("What do you want to do? \n a.Push \n b.Pop \n c.Peep \n d.Exit \n");

		scanf(" %c",&c);

		switch(c)
		{
			case 'a':	printf("Enter the value you want to be pushed onto the stack \n");
						scanf("%d",&data);
						push(data);
						printf("Value pushed \n");
						break;

			case 'b':	pop();
						break;

			case 'c':	peep();
						break;

			case 'd':exit(0);

			default: printf("Invalid option. Try again \n");

		}

	}

}



void push(int data)
{
	node *temp= (struct node*)malloc(sizeof(struct node));

	temp->data=data;

	temp->next=top;
	top=temp;

}



void pop()
{
	if(top==NULL)
	{
		printf("The stack is empty \n");
		return;
	}

	printf("The value popped is : %d \n", top->data);

	node *temp=top;

	top=top->next;

	free(temp);

}


void peep()
{
	if(top==NULL)
	{
		printf("The stack is empty\n");
		return;
	}

	node *ptr;
	ptr=top;

	while(ptr!=NULL)
	{
		printf("%d \n",ptr->data);

		ptr=ptr->next;

	}

}




