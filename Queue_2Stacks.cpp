#include <stdio.h>
#include <stdlib.h>
#define max 1000

int arr1[max],arr2[max],top1=-1,top2;

int *s1=arr1;
int *s2=arr2;

void dequeue();
int pop();
void push(int e);
void display();
void reverse();

void enqueue()
{
	top2=-1;
	int *temp;
	int data;
	if(top1==max-1)
	{
		printf("The queue is full. Perform a dequeue operation before inserting another element\n");
		return;
	}

	printf("Enter the element to be enqueued(inserted)\n");
	scanf(" %d",&data);

	if(top1==-1)
	{
		s1[++top1]=data;
		printf("Element enqueued(inserted) \n");
		return;
	}

	reverse();

	s2[++top2]=data;

	while(top1>=0)
		push(pop());

	temp=s1;
	s1=s2;
	s2=temp;

	top1=top2;

}

void reverse()
{
	int *temp;
	int i=top1;

	while(i>=0)
		s2[++top2]=s1[i--];

	temp=s1;
	s1=s2;
	s2=temp;

	top2=-1;

}


int pop()
{
	return s1[top1--];
}

void push(int e)
{
	s2[++top2]=e;
}

void dequeue()
{
	if(top1>=0)
		printf("The element dequeued is : %d \n",s1[top1--]);
	else
		printf("The queue is empty\n");

}

void display()
{
	int i;
	if(top1<0)
	{
		printf("The queue is empty \n");
		return;
	}

	i=top1;
	printf("Head -> 	\t");

	while(i>=0)
		printf("%d\t",s1[i--]);

	printf("<-Tail\n");

}


int main()
{
	char c;


	while(1)
	{

		printf("Enter your choice : \n a.Enqueue(Insert) \n b.Dequeue(Delete) \n c.Display Queue \n d.Exit \n");
		scanf(" %c",&c);
	switch(c)
	{
		case 'a' :	enqueue();break;

		case 'b' :	dequeue();break;

		case 'c' :	display();break;

		case 'd' :	exit(0);

		default  :	printf("Invalid Input. Please try again\n");

	}
	}

}









