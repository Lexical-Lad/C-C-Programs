#include <stdio.h>
#include <stdlib.h>
#define max 1000

int stack[max],top1=-1,top2=max;

void display1();
void display2();
void pop1();
void push1(int data);
void pop2();
void push2(int data);

int main()
{
	char c;int data;

	while(1)
	{
		printf("What do you want to do? \n a.Push(stack 1) \n b.Push(stack 2) \n c.Pop(stack 1) \n d.Pop(stack 2)\n e.Peep(stack 1)\n f.Peep(stack 2)\n g.Exit \n");
		scanf(" %c",&c);

		switch(c)
		{
			case 'a' :	if(top1==top2-1)
							printf("Overflow\n");
						else
						{
							printf("Enter the element to be pushed \n");
							scanf(" %d",&data);
							push1(data);
						}
						break;

			case 'b' :	if(top1==top2-1)
							printf("Overflow\n");
						else
						{
							printf("Enter the element to be pushed \n");
							scanf(" %d",&data);
							push2(data);
						}
						break;


			case 'c' :	pop1();
						break;

			case 'd' :	pop2();
						break;

			case 'e' :	display1();break;

			case 'f' :	display2();break;

			case 'g' :	exit(0);

			default  :	printf("Invalid Input. Please try again \n");

		}


	}

}


void push1(int data)
{
	stack[++top1]=data;
}

void push2(int data)
{
	stack[--top2]=data;
}

void pop1()
{
	if(top1<0)
		printf("The selected stack is empty.\n");
	else
		printf("The element popped is : %d \n",stack[top1--]);

}

void pop2()
{
	if(top2>max-1)
		printf("The selected stack is empty. \n");
	else
		printf("The element popped is  : %d \n",stack[top2++]);

}

void display1()
{
	int i=0;
	if(top1<0)
	{
		printf("The selected stack is empty.\n");
		return;
	}

	while(i<=top1)
		printf("%d \n",stack[i++]);

}

void display2()
{
	int i=max-1;

	if(top2>max-1)
	{
		printf("The selected stack is empty. \n");
		return;
	}

	while(i>=top2)
		printf("%d \n",stack[i--]);

}




