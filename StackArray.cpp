#include <stdio.h>
#include <stdlib.h>

const int  max=1000;

int a[max],top=-1;


void push(int data);
void pop();
void peep();


int main()
{
	int data;
	char c;


	while(1)
	{
		printf("What do you want to do? \n a. Push \n b.Pop \n c.Peep \n d.Exit \n ");

		scanf(" %c",&c);

		switch(c)
		{
			case 'a':	if(top==(max-1))
						{
							printf("The stack is full. No more values can be pushed. \n");
							continue;
						}

						printf("Enter the value you want ot push onto the stack \n");
						scanf("%d",&data);

						push(data);

						printf("Value pushed \n");
						break;

			case 'b': 	pop();
						break;

			case 'c': 	peep();
						break;

			case 'd': 	exit(0);

			default : 	printf("Invalid option. Try again\n");

		}

	}

}


void push(int data)
{
	a[++top]= data;
}

void pop()
{
	if(top<0)
	{
		printf("The stack is empty\n");
		return;
	}

	printf("The value popped is : %d \n",a[top]);

	top--;

}

void peep()
{
	int i;

	if(top<0)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("\n\n");
	for(i=0;i<=top;i++)
		printf(" %d \n",a[i]);

	printf("\n\n");

}





