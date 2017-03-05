#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	node *start,*ptr;
	int n,st,i;
	printf("Enter the number of elements :\n");
	scanf("%d",&n);

	start=(struct node*)malloc(sizeof(struct node));
	start->next=NULL;
	ptr=start;
	ptr->data=1;
	for(i=2;i<=n;i++)
	{
		ptr->next=(struct node*)malloc(sizeof(struct node));
		ptr=ptr->next;
		ptr->data=i;
	}

	ptr->next=start;

	printf("Enter the starting point :\n");
	scanf("%d",&st);

	printf("Enter the constraint 'n' such that every nth node is deleted :\n");
	scanf("%d",&n);

	ptr=start;

	while(ptr->data!=st)
	ptr=ptr->next;

	i=0;

	while(start->next!=start)
	{
		i++;
		if(i==(n-1)&&ptr->next!=start)
			{

				ptr->next=ptr->next->next;
				i=0;
			}
		else if (i==(n-1) && ptr->next==start)
			{
				start=start->next;
				ptr->next=start;
				i=0;
			}
			ptr=ptr->next;

	}

	printf("\nThe element remaining is : %d \n",ptr->data);
	free(start);

}

















