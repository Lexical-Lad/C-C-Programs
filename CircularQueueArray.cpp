#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

const int max=1000;
int q[max];
int front=-1,rear=-1;
void insert();
void deletion();
void display();

int main()

{
	char c;
	while(1)
	{
	printf("Enter your choice :\n a.Insert \n b.Delete \n c.Display \n d.Exit \n");

	scanf(" %c",&c);

	switch(c)
	{
		case 'a'	:	insert();break;

		case 'b'	:	deletion();break;

		case 'c' 	:	display();break;

		case 'd' 	:	 exit(0);

		default 	:	printf("Invalid Input. Try again \n");

	}
	}

}

void insert()

{
	int temp;

	if(((rear==max-1)&&(front==0))||(front==rear+1))
	{
		printf("The queue is full(Overflow) \n");
		return;
	}

	if(front!=0 && rear==(max-1))
	rear=0;


	printf("Enter the value to be inserted \n");
	scanf("%d",&temp);

	if(front==-1)
		front=0;

	q[++rear]=temp;

}


void deletion()
{
	if(front==-1)
	{
		printf("List is empty(underflow)\n");
		return;
	}

	printf("The value deleted is : %d \n",q[front]);

	if(front==rear)
	front=rear=-1;

	else if(front==max-1)
	front=0;

	else front++;

}

void display()
{
	int i=front;
	if(front ==-1)
	{
		printf("The list is empty\n");

		return;
	}

	if(front==rear)
	{
		printf("%d \n",q[front]);
		return;
	}

	while(i!=rear)
	{
		printf("%d \n",q[i]);

		i++;
		if(i==max)
		i=0;
	}
	printf("%d \n",q[i]);
}





