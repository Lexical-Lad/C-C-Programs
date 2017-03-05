#include <stdio.h>
#include <stdlib.h>

const int max=1000;

int arr1[max],arr2[max];
int head1=-1,tail1=-1;

int *q1=arr1;
int *q2=arr2;



int dequeue(int i);
void enqueue(int data,int i);
void pop();
void display();


void push()   // Enqueues the pushed element to q2, dequeues all elements of q1 and enqueues them to q2 and finally swaps the pointers of q1 and q2 for the next pass
{
	int *temp;
	int data,i;


	if(tail1==max-1)
	{
		printf("The stack is full(Overflow). Please perform a pop operation to free up space \n");
		return;
	}

	printf("Enter the element to be pushed\n");
	scanf("%d",&data);

	if(head1==-1)
	{
		q1[++head1]=data;
		tail1++;
		printf("Element Pushed \n");
		return;
	}

	else

	{
		i=head1;
		q2[head1]=data;

		while(i<=tail1)
		{
			enqueue(dequeue(i),i);
			i++;
		}
		tail1++;
	}

	temp=q1;
	q1=q2;
	q2=temp;

	printf("Element Pushed \n");
}


void pop()
{
		if(head==-1)
		{
			printf("The stack is empty \n");
			return;
		}

		if(head1<=tail1)
			printf("The element popped is : %d \n",q1[head1++]);

		if(head1>tail1)   //queue becomes empty after the current pop operation
		head1=tail1=-1;

}

int dequeue(int i)
{
	return q1[i];
}

void enqueue(int data,int i)
{
	q2[i+1]=data;
}

void display()
{
	int i=tail1;
	printf("Bottom -> \t");
	while(i>=head1)
	{
		printf("%d \t",q1[i]);
		i--;
	}
	printf("<- Top \n");
}

int main()

{
	char c;

	while(1)
	{
		printf("Enter your choice :\n a.Push \n b.Pop \n c.Peep \n d.Exit \n");
		scanf(" %c",&c);

		switch(c)
		{
			case 'a' :	 push();break;

			case 'b' :	 pop();break;

			case 'c' :	 display();break;

			case 'd' :	exit(0);

			default  :	printf("Invalid Input. Please try again\n");

		}


	}

}





