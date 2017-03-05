#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node
{
	struct node *next;
	int index;
};

typedef struct node node;

node *start=NULL;

void display();

int create()

{
	node *temp,*ptr;
	int n,i;
	printf("Enter the number 'n' such that the linked list would contain (n+1) nodes\n");
	scanf("%d",&n);

	ptr=start;

	for(i=0;i<=n;i++)
	{
		temp=(node *)malloc(sizeof(node));
		temp->index=i;
		temp->next=NULL;

		if(i==0)
			ptr=start=temp;
		else
		{
			ptr->next=temp;
			ptr=temp;
		}

	}

	return n;
}



int main()
{
	int n=create();
	int i;
	node *ptr,*temp;

	ptr=start;

	for(i=1;i<=(n/2);i++)
	{
		temp=ptr;

		while(temp->next->next!=NULL)
		temp=temp->next;

		temp->next->next=ptr->next;
		ptr->next=temp->next;
		temp->next=NULL;
		ptr=ptr->next->next;

	}

	display();
}

void display()
{
	node *ptr=start;

	while(ptr->next!=NULL)
	{
		printf("%d -> ",ptr->index);
		ptr=ptr->next;
	}
	printf("%d \n",ptr->index);
}




